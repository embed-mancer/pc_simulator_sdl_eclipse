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

static bool is_active = true;

static void refresh() {
}

typedef void (*click_handler_t)(void);

static void handle_back() {
  menu_navigate_go_back(&nav_state);
}

static void handle_up() {
  update_index(DIRECTION_UP);
  ui_helpers_calculate_y_positions(BACKLIGHT_ITEM_COUNT,
                                   nav_state->current_screen->elements);
}

static void handle_down() {
  update_index(DIRECTION_DOWN);
  ui_helpers_calculate_y_positions(BACKLIGHT_ITEM_COUNT,
                                   nav_state->current_screen->elements);
}

static click_handler_t click_handlers[] = {
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
  button_control_set_title(TEXT_ID_BLUETOOTH);
  screen_t* screen    = nav_state->current_screen;
  lv_obj_t** elements = screen->elements;

  label_color_e color                    = tool_get_color_base();
  const char* text[BACKLIGHT_ITEM_COUNT] = {"1", "2", "3",
                                            "4", "5", lang_text(TEXT_ID_AUTO)};

  for (int i = 0; i < BACKLIGHT_ITEM_COUNT; ++i) {
    label_pos_t pos = ui_helpers_init_label_position(
        270, 237, 500, 62, color, LABEL_FONT_HARMONYOS_24, VALUE_TYPE_CHAR,
        ui_helpers_init_label_value(text[i]));
    ui_helpers_create_label(menu_window_get(), &elements[i], pos);
    lv_obj_set_style_text_align(elements[i], LV_TEXT_ALIGN_CENTER, 0);
  }

  ui_helpers_calculate_y_positions(BACKLIGHT_ITEM_COUNT, screen->elements);
}

static void close_window() {
}

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
                                                 BACKLIGHT_ITEM_COUNT, 10);
  menu_component_t* component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  screen->component = component;

  menu_navigate_to(&nav_state, screen);
  open_window();
}
