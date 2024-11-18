#include "settings.h"
#include "../tool/tool.h"
#include "../screens/mobile_window.h"

#define SETTINGS_COUNT 3

extern void vehicle_init();
extern void fault_init();

static void refresh() {
}

typedef void (*click_handler_t)(void);

static void handle_set() {
  switch (nav_state->selected_index) {
  case 0:
    vehicle_init();
    break;
  case 1:
    fault_init();
    break;
  case 2:
    mobile_window_init();
    break;
  }
}

static void handle_back() {
  menu_navigate_go_back(&nav_state);
}

static void handle_up() {
  if (nav_state->selected_index == 0) {
    nav_state->prev->selected_index = 5;
    menu_navigate_go_back(&nav_state);
    return;
  }
  update_index(DIRECTION_UP);
  lv_obj_t **elements = nav_state->current_screen->elements;
  lv_obj_set_y(elements[6], 70 + 60 * nav_state->selected_index);
}

static void handle_down() {
  if (nav_state->selected_index == 2) {
    nav_state->prev->selected_index = 0;
    menu_navigate_go_back(&nav_state);
    return;
  }
  update_index(DIRECTION_DOWN);
  lv_obj_t **elements = nav_state->current_screen->elements;
  lv_obj_set_y(elements[6], 70 + 60 * nav_state->selected_index);
}

static click_handler_t click_handlers[] = {
    [CLICK_SHORT_SET]  = handle_set,
    [CLICK_SHORT_BACK] = handle_back,
    [CLICK_SHORT_UP]   = handle_up,
    [CLICK_SHORT_DOWN] = handle_down,
};

static bool handle_click_event(const click_e click) {
  if (click < sizeof(click_handlers) / sizeof(click_handler_t) &&
      click_handlers[click]) {
    click_handlers[click]();
  }
  print_navigation_state(nav_state);
  return true;
}

static void toggle_day_night() {
}

static void destroy() {
  menu_navigate_free(&nav_state);
}

static void open_window() {
}

static void close_window() {
}

static void on_return() {
  button_control_set_title(TEXT_ID_SETTINGS);
}

void settings2_init(int index) {
  menu_item_t *items = (menu_item_t *)malloc(3 * sizeof(menu_item_t));
  if (!items)
    return;

  items[0] = (menu_item_t){"setting vehicle", SETTING_VEHICLE, OPTION_PAGE};
  items[1] = (menu_item_t){"setting fault", SETTING_FAULT, OPTION_PAGE};
  items[2] = (menu_item_t){"setting mobile", SETTING_MOBILE, OPTION_PAGE};

  screen_t *screen =
      menu_navigate_create_screen(SETTING_MAIN, "setting 2", items, 3, 20);
  menu_component_t *component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  screen->component   = component;
  lv_obj_t **elements = screen->elements;

  ui_helpers_menu_image(elements, "selected.png", 6, 293, 70);
  label_params_t params = ui_helpers_params(320, 70, lang_text(TEXT_ID_VEHICLE),
                                            RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window_get(), &elements[0], &elements[10], params);

  params = ui_helpers_params(320, 130, lang_text(TEXT_ID_FAULT),
                             RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window_get(), &elements[1], &elements[11], params);

  params = ui_helpers_params(320, 190, lang_text(TEXT_ID_MOBILE),
                             RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window_get(), &elements[2], &elements[12], params);

  menu_navigate_to(&nav_state, screen);
  nav_state->selected_index            = index;
  nav_state->current_screen->on_return = on_return;
  lv_obj_set_y(elements[6], 70 + 60 * index);
}
