#include "menu_navigate.h"
#include "../config/config.h"
#include "../other/motor_model.h"
#include "settings.h"

#define DISPLAY_COUNT 3
int y_pos[DISPLAY_COUNT];

static bool is_active = true;

static void refresh() {}

typedef void (*click_handler_t)(void);
static void toggle_day_night();
static void open_window();

static void update_selection_display() {
  lv_obj_t** elements = nav_state->current_screen->elements;
  int selected_index = nav_state->selected_index;
  lv_color_t color = tool_get_theme_color();
  for (int i = 0; i < DISPLAY_COUNT; ++i) {
    ui_helpers_set_element_style(elements[i], i == selected_index, color);
    int line_height = lv_font_get_line_height(
        tool_get_font(i == selected_index ? LABEL_FONT_HARMONYOS_36
                                          : LABEL_FONT_HARMONYOS_24));
    lv_obj_set_y(elements[i], (62 - line_height) / 2 + y_pos[i]);
  }
  lv_obj_set_y(elements[9], y_pos[nav_state->selected_index]);
}

static void apply_day_night_setting(int setting) {
  config_set_data(CONFIG_DAYNIGHT_DISPLAY, setting);
  motor_model_set_day_night_mode(setting);
  toggle_day_night();
}

static void handle_set() {
  int selected_index = nav_state->selected_index;
  config_set_data(CONFIG_DAYNIGHT_SETTING, selected_index);
  if (selected_index < 2) {
    apply_day_night_setting(selected_index);
    menu_window_toggle_display();
    button_control_toggle_display();
    open_window();
  }
}
static void handle_back() { menu_navigate_go_back(&nav_state); }

static void handle_up() {
  update_index(DIRECTION_UP);
  update_selection_display();
}

static void handle_down() {
  update_index(DIRECTION_DOWN);
  update_selection_display();
}

static click_handler_t click_handlers[] = {
    [CLICK_SHORT_SET] = handle_set,
    [CLICK_SHORT_BACK] = handle_back,
    [CLICK_SHORT_UP] = handle_up,
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
  lv_color_t color = tool_get_theme_color();
  for (int i = 0; i < 3; ++i) {
    lv_obj_set_style_text_color(elements[i], color, 0);
  }
}

static void destroy() {}

static void open_window() {
  button_control_set_title(TEXT_ID_DISPLAY);
  screen_t* screen = nav_state->current_screen;
  lv_obj_t** elements = screen->elements;

  label_color_e color = tool_get_color_base();
  label_font_e font = LABEL_FONT_HARMONYOS_24;

  const char* texts[DISPLAY_COUNT] = {lang_text(TEXT_ID_DAY),
                                      lang_text(TEXT_ID_NIGHT),
                                      lang_text(TEXT_ID_AUTO)};
  ui_helpers_centered_y_positions(y_pos, DISPLAY_COUNT, 62);
  for (int i = 0; i < DISPLAY_COUNT; ++i) {
    ui_helpers_create_label_center(menu_window_get(), &elements[i], 268,
                                   y_pos[i], 500, 62, color, font, texts[i]);
  }
  ui_helpers_menu_image(elements, "selected2.png", 9, 292, y_pos[1]);
  ui_helpers_menu_image(elements, "line.png", 3, 292, y_pos[1]);
  ui_helpers_menu_image(elements, "line.png", 4, 292, y_pos[2]);
  nav_state->selected_index = config_get_data(CONFIG_DAYNIGHT_SETTING);
  update_selection_display();
}

static void close_window() {}

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
