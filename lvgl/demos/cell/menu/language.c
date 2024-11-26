#include "menu_navigate.h"
#include "../config/config.h"
#include "../language/lang.h"

int y_pos[2];
static bool is_active = true;

static void refresh() {}

static void update_selection_display() {
  lv_obj_t** elements = nav_state->current_screen->elements;
  int selected_index = nav_state->selected_index;
  lv_color_t color = tool_get_theme_color();
  for (int i = 0; i < LANGUAGE_COUNT; ++i) {
    ui_helpers_set_element_style(elements[i], i == selected_index, color);
    int line_height = lv_font_get_line_height(
        tool_get_font(i == selected_index ? LABEL_FONT_HARMONYOS_36
                                          : LABEL_FONT_HARMONYOS_24));
    lv_obj_set_y(elements[i], (62 - line_height) / 2 + y_pos[i]);
  }
  lv_obj_set_y(elements[9], y_pos[nav_state->selected_index]);
}

static bool handle_click_event(const click_e click) {
  screen_t* screen = nav_state->current_screen;
  int index = nav_state->selected_index;

  switch (click) {
    case CLICK_SHORT_SET:
      config_set_data(CONFIG_UI_LANGUAGE, nav_state->selected_index);
      lang_set(nav_state->selected_index);
      break;
    case CLICK_SHORT_BACK:
      is_active = false;
      menu_navigate_go_back(&nav_state);
      break;
    case CLICK_SHORT_UP:
      update_index(DIRECTION_UP);
      update_selection_display();
      break;
    case CLICK_SHORT_DOWN:
      update_index(DIRECTION_UP);
      update_selection_display();
      break;
  }
  print_navigation_state(nav_state);
  return is_active;
}

static void toggle_day_night() {}

static void destroy() {}

static void open_window() {
  button_control_set_title(TEXT_ID_LANGUAGE);
  screen_t* screen = nav_state->current_screen;
  lv_obj_t** elements = screen->elements;

  label_color_e color = tool_get_color_base();
  label_font_e font = LABEL_FONT_HARMONYOS_24;
  const char* texts[LANGUAGE_COUNT] = {"中文", "English"};

    ui_helpers_centered_y_positions(y_pos, LANGUAGE_COUNT, 62);
  for (int i = 0; i < LANGUAGE_COUNT; ++i) {
    ui_helpers_create_label_center(menu_window_get(), &elements[i], 268,
                                   y_pos[i], 500, 62, color, font, texts[i]);
  }
  ui_helpers_menu_image(elements, "selected2.png", 9, 292, y_pos[0]);
  ui_helpers_menu_image(elements, "line.png", 3, 292, y_pos[1]);
  nav_state->selected_index = config_get_data(CONFIG_UI_LANGUAGE);
  update_selection_display();
}

static void close_window() {}

void language_init() {
  menu_item_t* items = (menu_item_t*)malloc(2 * sizeof(menu_item_t));
  if (!items)
    return;

  items[0] = (menu_item_t){"Chinese", -1, OPTION_NULL};
  items[1] = (menu_item_t){"English", -1, OPTION_NULL};

  screen_t* screen =
      menu_navigate_create_screen(SETTING_LANGUAGE, "language", items, 2, 10);
  menu_component_t* component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  screen->component = component;

  menu_navigate_to(&nav_state, screen);
  open_window();
}
