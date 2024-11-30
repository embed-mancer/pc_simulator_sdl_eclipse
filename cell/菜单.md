
# 菜单系统页面管理说明文档

## 概述
本文档描述了一个基于页面管理的菜单系统实现，用于嵌入式设备。设计中确保切换界面时，之前的页面不会被销毁，而是保持在内存中隐藏，以实现快速切换和状态保持。

## 设计原则
1. **页面持久化**：界面切换时，之前的页面不会被销毁，从而保持其状态，便于后续访问。
2. **导航状态管理**：通过导航栈（`navigation_state_t`），管理当前页面和之前的页面，实现返回功能。
3. **组件化设计**：每个组件被封装为一个 `menu_component_t` 对象，包含初始化、事件处理和清理等操作。
4. **关注点分离**：系统将 UI 管理（如 `menu_component.c`）与导航逻辑（如 `menu_navigate.c`）以及菜单整体处理（如 `menu_manager.c`）进行分离。

## 核心模块

### 1. 菜单管理器（Menu Manager）
`menu_manager` 模块负责初始化菜单系统，处理组件切换，并管理菜单组件的生命周期。

- **初始化**：
  ```c
  void menu_manager() {
      side_bar_init(); // 初始化侧边栏
      page_id = PAGE_VEHICLE_SETTINGS; // 设置初始页面
      menu_component_t* component = menu_manager_create_component(page_id);
      if (component)
          menu_manager_switch_page(component); // 切换到初始页面
  }
  ```

- **页面切换**：
  组件切换时，删除前组件并激活目标组件。
  ```c
  void menu_manager_switch_page(menu_component_t* component) {
      if (current_component) {
          current_component->destroy(); // 销毁当前页面
          free(current_component);     // 释放内存
          current_component = NULL;
      }
      if (component) {
          side_bar_update(page_id); // 更新侧边栏
          current_component = component;
          current_component->open_window(); // 打开目标页面
      }
  }
  ```

### 2. 菜单导航（Menu Navigation）
`menu_navigate` 模块提供了导航状态的管理，实现页面导航和返回功能。

- **导航到新页面**：
  使用 `menu_navigate_to` 方法隐藏当前页面并显示目标页面。
  ```c
  navigation_state_t* menu_navigate_to(navigation_state_t* current_state, screen_t* new_screen) {
      if (!new_screen) return current_state;

      navigation_state_t* new_state = malloc(sizeof(navigation_state_t));
      if (!new_state) return current_state;

      new_state->current_screen = new_screen;
      new_state->selected_index = 0;
      new_state->prev = current_state;

      if (current_state && current_state->current_screen) {
          menu_navigate_hide_screen(current_state->current_screen); // 隐藏当前页面
      }
      menu_navigate_show_screen(new_screen); // 显示新页面
      return new_state;
  }
  ```

- **返回上一页面**：
  使用 `menu_navigate_go_back` 方法返回之前的页面，同时释放当前页面的资源。
  ```c
  navigation_state_t* menu_navigate_go_back(navigation_state_t* current_state) {
      if (current_state && current_state->prev) {
          navigation_state_t* prev_state = current_state->prev;
          menu_navigate_free(current_state); // 释放当前状态
          menu_navigate_show_screen(prev_state->current_screen); // 显示前一个页面
          return prev_state;
      }
      return current_state;
  }
  ```

### 3. 菜单组件（Menu Component）
`menu_component` 模块定义了界面组件的基本结构及相关操作。

- **组件定义**：
  ```c
  typedef struct {
      void (*refresh)();
      bool (*handle_click_event)(const click_e);
      void (*toggle_day_night)();
      void (*destroy)();
      void (*open_window)();
      void (*close_window)();
  } menu_component_t;
  ```

- **初始化组件**：
  ```c
  void init_component(menu_component_t* component, void (*refresh)(),
                      bool (*handle_click_event)(const click_e),
                      void (*toggle_day_night)(), void (*destroy)(),
                      void (*open_window)(), void (*close_window)()) {
      if (!component) return;

      *component = (menu_component_t){
          .refresh = refresh,
          .handle_click_event = handle_click_event,
          .toggle_day_night = toggle_day_night,
          .destroy = destroy,
          .open_window = open_window,
          .close_window = close_window};
  }
  ```

### 4. 侧边栏（Side Bar）
`side_bar` 模块实现了菜单的侧边栏，负责页面的可视化导航。

## 功能示例
### 页面切换
用户可以通过上下按键导航，点击确认键切换页面。
- 按键事件处理：
  ```c
  void handle_click_event(const click_e click) {
      switch (click) {
      case CLICK_SHORT_UP:
          handle_up();
          break;
      case CLICK_SHORT_DOWN:
          handle_down();
          break;
      case CLICK_SHORT_SET:
          handle_set();
          break;
      case CLICK_SHORT_BACK:
          handle_back();
          break;
      }
  }
  ```

### 页面返回
在子页面点击返回键，可以回到上一层页面。
```c
void handle_back() {
    nav_state = menu_navigate_go_back(&nav_state);
}
```

## 总结
该系统通过页面持久化和导航栈管理，提供了高效、灵活的菜单导航功能，适用于资源受限的嵌入式设备。
