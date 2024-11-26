#include "menu_navigate.h"

static bool is_active = true;

static void refresh() {
}

typedef void (*click_handler_t)(void);

static void handle_set() {
  menu_navigate_go_back(&nav_state);
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
  lv_obj_t** elements = nav_state->current_screen->elements;

  int y_pos[5];
  for (size_t i = 0; i < 5; ++i) y_pos[i] = 70 + 68 * i;

  label_color_e color      = tool_get_color_base();

  ui_helpers_menu_image(elements, "selected.png", 29, 290, y_pos[3]);

  ui_helpers_menu_image(elements, "icon_basic.png", 1, 301, 77);
  ui_helpers_menu_image(elements, "arrow_down.png", 2, 755, y_pos[0] + 20);
  ui_helpers_menu_image(elements, "icon_odo.png", 3, 295, 147);
  ui_helpers_menu_image(elements, "arrow_down.png", 4, 755, y_pos[1] + 20);
  ui_helpers_menu_image(elements, "icon_trip.png", 5, 295, 215);
  ui_helpers_menu_image(elements, "arrow_down.png", 6, 755, y_pos[2] + 20);
  ui_helpers_menu_image(elements, "icon_fault.png", 7, 293, 284);
  ui_helpers_menu_image(elements, "arrow_top.png", 8, 755, y_pos[3] + 20);

  ui_helpers_create_label_left(menu_window_get(), &elements[9], 345, y_pos[0],
                               300, 48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_BASIC));
  ui_helpers_create_label_left(menu_window_get(), &elements[10], 345, y_pos[1],
                               300, 48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_ODO));
  ui_helpers_create_label_left(menu_window_get(), &elements[11], 345, y_pos[2],
                               300, 48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_TRIP));
  ui_helpers_create_label_left(menu_window_get(), &elements[12], 345, y_pos[3],
                               300, 48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_FAULT_INFO));

  ui_helpers_create_label_left(menu_window_get(), &elements[13], 345,
                               y_pos[3] + 58, 300, 48, color,
                               LABEL_FONT_HARMONYOS_24, "info 1");
  ui_helpers_create_label_left(menu_window_get(), &elements[14], 345,
                               y_pos[3] + 106, 300, 48, color,
                               LABEL_FONT_HARMONYOS_24, "info 2");
}

static void close_window() {
}

void fault_info() {
  screen_t* screen = menu_navigate_create_screen(0, "trip info", NULL, 0, 30);
  menu_component_t* component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  screen->component = component;

  menu_navigate_to(&nav_state, screen);
  open_window();
}
