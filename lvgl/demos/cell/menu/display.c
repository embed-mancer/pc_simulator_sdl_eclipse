#include "menu_navigate.h"
#include "../config/config.h"
#include "../other/motor_model.h"
#include "settings.h"

static bool is_active = true;
#define DISPLAY_COUNT 3

static void refresh() {
}

typedef void (*click_handler_t)(void);
static void toggle_day_night();

static void handle_set() {
  config_set_data(CONFIG_DAYNIGHT_SETTING, nav_state->selected_index);
  if (nav_state->selected_index < 2) {
    config_set_data(CONFIG_DAYNIGHT_DISPLAY, nav_state->selected_index);
    motor_model_set_day_night_mode(nav_state->selected_index);
    menu_window_toggle_display();
    button_control_toggle_display();
    toggle_day_night();
  }
}

static void handle_back() {
  menu_navigate_go_back(&nav_state);
}

static void handle_up() {
  update_index(DIRECTION_UP);
  ui_helpers_calculate_y_positions(DISPLAY_COUNT,
                                   nav_state->current_screen->elements);
}

static void handle_down() {
  update_index(DIRECTION_DOWN);
  ui_helpers_calculate_y_positions(DISPLAY_COUNT,
                                   nav_state->current_screen->elements);
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
  lv_obj_t** elements = nav_state->current_screen->elements;
  lv_color_t color    = tool_get_theme_color();
  for (int i = 0; i < 3; ++i) {
    lv_obj_set_style_text_color(elements[i], color, 0);
  }
}

static void destroy() {
}

static void open_window() {
  button_control_set_title(TEXT_ID_DISPLAY);
  screen_t* screen    = nav_state->current_screen;
  lv_obj_t** elements = screen->elements;

  label_color_e color = tool_get_color_base();

  const char* texts[DISPLAY_COUNT] = {lang_text(TEXT_ID_DAY),
                                      lang_text(TEXT_ID_NIGHT),
                                      lang_text(TEXT_ID_AUTO)};

  for (int i = 0; i < DISPLAY_COUNT; ++i) {
    label_pos_t pos = ui_helpers_init_label_position(
        270, 237, 500, 62, color, LABEL_FONT_HARMONYOS_24, VALUE_TYPE_CHAR,
        ui_helpers_init_label_value(texts[i]));
    ui_helpers_create_label(menu_window_get(), &elements[i], pos);
    lv_obj_set_style_text_align(elements[i], LV_TEXT_ALIGN_CENTER, 0);
  }

  ui_helpers_calculate_y_positions(DISPLAY_COUNT, screen->elements);
}

static void close_window() {
}

void display_init() {
  menu_item_t* items = malloc(DISPLAY_COUNT * sizeof(menu_item_t));
  if (!items)
    return;

  const menu_item_t default_items[DISPLAY_COUNT] = {
      {"day", -1, OPTION_NULL},
      {"night", -1, OPTION_NULL},
      {"auto", -1, OPTION_NULL},
  };
  memcpy(items, default_items, sizeof(default_items));

  screen_t* screen = menu_navigate_create_screen(SETTING_DISPLAY, "display",
                                                 items, DISPLAY_COUNT, 10);

  menu_component_t* component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  screen->component = component;

  menu_navigate_to(&nav_state, screen);
  open_window();
}
