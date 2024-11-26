#include "menu_navigate.h"

static bool is_active = true;
#define FAULT_COUNT 5

static void refresh() {
}

typedef void (*click_handler_t)(void);

static void handle_set() {
}

static void handle_back() {
  menu_navigate_go_back(&nav_state);
}

static void handle_up() {
}

static void handle_down() {
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
  return is_active;
}

static void toggle_day_night() {
}

static void destroy() {
}

static void open_window() {
  button_control_set_title(TEXT_ID_FAULT);

  lv_obj_t** elements = nav_state->current_screen->elements;
  label_color_e color = tool_get_color_base();

  int y_pos[4] = {0};
  for (size_t i = 0; i < 4; ++i) y_pos[i] = 100 + 60 * i;

  ui_helpers_create_label_left(menu_window_get(), &elements[0], 391, y_pos[0],
                               200, 48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_FAULT_CURRENT));
  ui_helpers_create_label_left(menu_window_get(), &elements[1], 391, y_pos[1],
                               200, 48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_FAULT_HISTORY));
  ui_helpers_create_label_left(menu_window_get(), &elements[2], 391, y_pos[2],
                               200, 48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_FAULT_OS));
  ui_helpers_create_label_left(menu_window_get(), &elements[3], 391, y_pos[3],
                               200, 48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_FAULT_MCU));

  ui_helpers_create_label_left(menu_window_get(), &elements[4], 550, y_pos[0],
                               200, 48, color, LABEL_FONT_HARMONYOS_24,
                               "------");
  ui_helpers_create_label_left(menu_window_get(), &elements[5], 550, y_pos[1],
                               200, 48, color, LABEL_FONT_HARMONYOS_24,
                               "------");
  ui_helpers_create_label_left(menu_window_get(), &elements[6], 550, y_pos[2],
                               200, 48, color, LABEL_FONT_HARMONYOS_24,
                               "------");
  ui_helpers_create_label_left(menu_window_get(), &elements[7], 550, y_pos[3],
                               200, 48, color, LABEL_FONT_HARMONYOS_24,
                               "------");
}

static void close_window() {
}

void fault_init() {
  screen_t* screen =
      menu_navigate_create_screen(SETTING_FAULT, "fault", NULL, 0, 10);
  menu_component_t* component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  screen->component = component;

  menu_navigate_to(&nav_state, screen);
  open_window();
}
