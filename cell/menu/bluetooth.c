#include "menu_navigate.h"

#define BLUETOOTH_COUNT 2

static bool is_active = true;
static int y_pos[2]   = {0};

static void refresh() {
}

typedef void (*click_handler_t)(void);

static void handle_set() {
}

static void handle_back() {
  menu_navigate_go_back(&nav_state);
}

static void handle_up() {
  update_index(DIRECTION_UP);
  lv_obj_t** elements = nav_state->current_screen->elements;
  lv_obj_set_y(elements[9], y_pos[nav_state->selected_index]);
}

static void handle_down() {
  update_index(DIRECTION_DOWN);
  lv_obj_t** elements = nav_state->current_screen->elements;
  lv_obj_set_y(elements[9], y_pos[nav_state->selected_index]);
}

static click_handler_t click_handlers[] = {
    [CLICK_SHORT_UP]   = handle_up,
    [CLICK_SHORT_DOWN] = handle_down,
    [CLICK_SHORT_BACK] = handle_back,
    [CLICK_SHORT_SET]  = handle_set,
};

static bool handle_click_event(const click_e click) {
  if (click < sizeof(click_handlers) / sizeof(click_handler_t) &&
      click_handlers[click]) {
    click_handlers[click]();
  }
  print_navigation_state(nav_state);
  return is_active;
}

static void toggle_day_night() {
}

static void destroy() {
}

static void open_window() {
  button_control_set_title(TEXT_ID_BLUETOOTH);
  lv_obj_t** elements = nav_state->current_screen->elements;

  label_color_e color      = tool_get_color_base();

  y_pos[0] = 210;
  y_pos[1] = 280;
  ui_helpers_menu_image(elements, "selected2.png", 9, 290, y_pos[0]);

  ui_helpers_create_label_left(menu_window_get(), &elements[0], 391, 140, 200,
                               48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_BT_NAME));
  ui_helpers_create_label_left(menu_window_get(), &elements[3], 550, 140, 200,
                               48, color, LABEL_FONT_HARMONYOS_24, "Nemausa");
  ui_helpers_create_label_left(menu_window_get(), &elements[1], 391, y_pos[0],
                               200, 48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_BT_CONNECT));
  ui_helpers_create_label_left(menu_window_get(), &elements[4], 550, y_pos[0],
                               200, 48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_BT_OPEN));
  ui_helpers_create_label_left(menu_window_get(), &elements[2], 391, y_pos[1],
                               200, 48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_BT_SYNC));
  ui_helpers_create_label_left(menu_window_get(), &elements[5], 550, y_pos[1],
                               200, 48, color, LABEL_FONT_HARMONYOS_24, "[2]");
}

static void close_window() {
}

void bluetooth_init() {
  menu_item_t* items = (menu_item_t*)malloc(2 * sizeof(menu_item_t));
  if (!items)
    return;

  items[0] = (menu_item_t){"status", -1, OPTION_NULL};
  items[1] = (menu_item_t){"sync", -1, OPTION_NULL};

  screen_t* screen =
      menu_navigate_create_screen(SETTING_BLUETOOTH, "bluetooth", items, 2, 10);
  menu_component_t* component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  screen->component = component;

  menu_navigate_to(&nav_state, screen);
  open_window();
}
