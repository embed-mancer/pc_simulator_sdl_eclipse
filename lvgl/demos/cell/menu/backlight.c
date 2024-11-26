#include "menu_navigate.h"

typedef enum {
  BACKLIGHT_LEVEL_1,
  BACKLIGHT_LEVEL_2,
  BACKLIGHT_LEVEL_3,
  BACKLIGHT_LEVEL_4,
  BACKLIGHT_LEVEL_5,
  BACKLIGHT_AUTO,
  BACKLIGHT_ITEM_COUNT,
} backlight_level_e;

int y_pos[BACKLIGHT_ITEM_COUNT];

static bool is_active = true;

static void refresh() {}

typedef void (*click_handler_t)(void);

static void handle_back() { menu_navigate_go_back(&nav_state); }

static void set_element_style(lv_obj_t* element, bool selected,
                              lv_color_t color) {
  const lv_font_t* font =
      selected ? &HarmonyOS_Sans_SC_36 : &HarmonyOS_Sans_SC_24;
  lv_obj_set_style_text_font(element, font, 0);
  lv_obj_set_style_text_color(element, color, 0);
}

static void update_selection_display() {
  lv_obj_t** elements = nav_state->current_screen->elements;
  int selected_index = nav_state->selected_index;
  lv_color_t color = tool_get_theme_color();
  for (int i = 0; i < BACKLIGHT_ITEM_COUNT; ++i) {
    set_element_style(elements[i], i == selected_index, color);
    int line_height = lv_font_get_line_height(
        tool_get_font(i == selected_index ? LABEL_FONT_HARMONYOS_36
                                          : LABEL_FONT_HARMONYOS_24));
    lv_obj_set_y(elements[i], (62 - line_height) / 2 + y_pos[i]);
  }
  lv_obj_set_y(elements[19], y_pos[nav_state->selected_index]);
}

static void handle_up() {
  update_index(DIRECTION_UP);
  update_selection_display();
}

static void handle_down() {
  update_index(DIRECTION_DOWN);
  update_selection_display();
}

static click_handler_t click_handlers[] = {
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

static void toggle_day_night() {}

static void destroy() {}

static void open_window() {
  button_control_set_title(TEXT_ID_BLUETOOTH);
  screen_t* screen = nav_state->current_screen;
  lv_obj_t** elements = screen->elements;

  label_color_e color = tool_get_color_base();
  label_font_e font = LABEL_FONT_HARMONYOS_24;
  const char* texts[BACKLIGHT_ITEM_COUNT] = {"1", "2", "3",
                                             "4", "5", lang_text(TEXT_ID_AUTO)};

  ui_helpers_centered_y_positions(y_pos, 6, 62);
  for (int i = 0; i < 6; ++i) {
    ui_helpers_create_label_center(menu_window_get(), &elements[i], 268,
                                   y_pos[i], 500, 62, color, font, texts[i]);
  }
  ui_helpers_menu_image(elements, "selected2.png", 19, 292, y_pos[0]);
  for (int i = 1; i < BACKLIGHT_ITEM_COUNT; ++i)
    ui_helpers_menu_image(elements, "line.png", 6 + i, 292, y_pos[i]);

  update_selection_display();
}

static void close_window() {}

void backlight_init() {
  menu_item_t* items =
      (menu_item_t*)malloc(BACKLIGHT_ITEM_COUNT * sizeof(menu_item_t));
  if (!items)
    return;

  items[0] = (menu_item_t){"1", -1, OPTION_NULL};
  items[1] = (menu_item_t){"2", -1, OPTION_NULL};
  items[2] = (menu_item_t){"3", -1, OPTION_NULL};
  items[3] = (menu_item_t){"4", -1, OPTION_NULL};
  items[4] = (menu_item_t){"5", -1, OPTION_NULL};
  items[5] = (menu_item_t){"auto", -1, OPTION_NULL};

  screen_t* screen = menu_navigate_create_screen(0, "backlight", items,
                                                 BACKLIGHT_ITEM_COUNT, 20);
  menu_component_t* component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  screen->component = component;

  menu_navigate_to(&nav_state, screen);
  open_window();
}
