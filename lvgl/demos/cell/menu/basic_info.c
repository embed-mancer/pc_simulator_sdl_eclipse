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

static void line() {
}

static void frame() {
}

static void open_window() {
  lv_obj_t** elements = nav_state->current_screen->elements;

  int y_pos[5];
  for (int i = 0; i < 5; ++i) y_pos[i] = 70 + 68 * i;

  const char* theme_suffix = tool_get_theme_suffix();
  label_color_e color      = tool_get_color_base();

  ui_helpers_menu_image(elements, "selected.png", 29, 292, y_pos[0]);
  ui_helpers_menu_image(elements, "icon_basic.png", 1, 301, 77);
  ui_helpers_menu_image(elements, "arrow_top.png", 2, 755, y_pos[0] + 20);
  ui_helpers_menu_image(elements, "icon_odo.png", 4, 300, 376);
  ui_helpers_menu_image(elements, "arrow_down.png", 5, 755, 394);
  ui_helpers_menu_image(elements, "icon_trip.png", 7, 300, 426);
  ui_helpers_menu_image(elements, "arrow_down.png", 8, 755, 441);
  ui_helpers_menu_image(elements, "basic_bg.png", 9, 292, 116);
  ui_helpers_menu_image(elements, "basic_frame.png", 10, 302, 126);
  ui_helpers_menu_image(elements, "basic_frame.png", 11, 462, 126);
  ui_helpers_menu_image(elements, "basic_frame.png", 12, 622, 126);
  ui_helpers_menu_image(elements, "basic_motor.png", 13, 430, 190);

  ui_helpers_create_label_left(menu_window_get(), &elements[0], 345, y_pos[0],
                               300, 48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_BASIC));

  ui_helpers_create_label_left(menu_window_get(), &elements[3], 345, 366, 300,
                               48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_ODO));

  ui_helpers_create_label_left(menu_window_get(), &elements[6], 345, 416, 300,
                               48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_TRIP));

  label_pos_t pos_voltage = ui_helpers_init_label_position(
      302, 140, 156, 30, color, LABEL_FONT_HARMONYOS_28, VALUE_TYPE_CHAR,
      (label_value_t){"12.0v"});
  ui_helpers_create_label(menu_window_get(), &elements[14], pos_voltage);
  lv_obj_set_style_text_align(elements[14], LV_TEXT_ALIGN_CENTER, 0);
  pos_voltage = ui_helpers_init_label_position(
      302, 175, 156, 20, LABEL_COLOR_GREEN, LABEL_FONT_HARMONYOS_16,
      VALUE_TYPE_CHAR, ui_helpers_init_label_value(lang_text(TEXT_ID_VOLTAGE)));
  ui_helpers_create_label(menu_window_get(), &elements[15], pos_voltage);
  lv_obj_set_style_text_align(elements[15], LV_TEXT_ALIGN_CENTER, 0);

  label_pos_t pos_range = ui_helpers_init_label_position(
      462, 140, 156, 30, color, LABEL_FONT_HARMONYOS_28, VALUE_TYPE_CHAR,
      (label_value_t){"999km"});
  ui_helpers_create_label(menu_window_get(), &elements[16], pos_range);
  lv_obj_set_style_text_align(elements[16], LV_TEXT_ALIGN_CENTER, 0);
  pos_range = ui_helpers_init_label_position(
      462, 175, 156, 20, LABEL_COLOR_GREEN, LABEL_FONT_HARMONYOS_16,
      VALUE_TYPE_CHAR, ui_helpers_init_label_value(lang_text(TEXT_ID_RANGE)));
  ui_helpers_create_label(menu_window_get(), &elements[17], pos_range);
  lv_obj_set_style_text_align(elements[17], LV_TEXT_ALIGN_CENTER, 0);

  label_pos_t pos_temp = ui_helpers_init_label_position(
      622, 140, 156, 30, color, LABEL_FONT_HARMONYOS_28, VALUE_TYPE_CHAR,
      (label_value_t){"50°C"});
  ui_helpers_create_label(menu_window_get(), &elements[18], pos_temp);
  lv_obj_set_style_text_align(elements[18], LV_TEXT_ALIGN_CENTER, 0);
  pos_temp = ui_helpers_init_label_position(
      622, 175, 156, 20, LABEL_COLOR_GREEN, LABEL_FONT_HARMONYOS_16,
      VALUE_TYPE_CHAR,
      ui_helpers_init_label_value(lang_text(TEXT_ID_TEMPERATURE)));
  ui_helpers_create_label(menu_window_get(), &elements[19], pos_temp);
  lv_obj_set_style_text_align(elements[19], LV_TEXT_ALIGN_CENTER, 0);

  label_pos_t pos_bar = ui_helpers_init_label_position(
      330, 290, 100, 20, color, LABEL_FONT_HARMONYOS_16, VALUE_TYPE_CHAR,
      ui_helpers_init_label_value("2.2 bar"));
  ui_helpers_create_label(menu_window_get(), &elements[20], pos_bar);
  pos_bar = ui_helpers_init_label_position(
      690, 290, 100, 20, color, LABEL_FONT_HARMONYOS_16, VALUE_TYPE_CHAR,
      ui_helpers_init_label_value("2.5 bar"));
  ui_helpers_create_label(menu_window_get(), &elements[21], pos_bar);

  label_pos_t pos_bar_temp = ui_helpers_init_label_position(
      330, 320, 100, 20, color, LABEL_FONT_HARMONYOS_16, VALUE_TYPE_CHAR,
      ui_helpers_init_label_value("30 °C"));
  ui_helpers_create_label(menu_window_get(), &elements[22], pos_bar_temp);
  pos_bar_temp = ui_helpers_init_label_position(
      690, 320, 100, 20, color, LABEL_FONT_HARMONYOS_16, VALUE_TYPE_CHAR,
      ui_helpers_init_label_value("30 °C"));
  ui_helpers_create_label(menu_window_get(), &elements[23], pos_bar_temp);
}

static void close_window() {
}

void basic_info() {
  screen_t* screen = menu_navigate_create_screen(0, "basic info", NULL, 0, 30);
  menu_component_t* component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  screen->component = component;

  menu_navigate_to(&nav_state, screen);
  open_window();
}
