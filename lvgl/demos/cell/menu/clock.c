#include "menu_navigate.h"

#define TIME_X_CENTER 500
#define TIME_Y_POSITION 204
#define FIX_WIDTH 50
#define COLON_WIDTH 20

typedef void (*click_handler_t)(void);

typedef struct {
  int hour1;
  int hour2;
  int min1;
  int min2;
} time_data_t;

static time_data_t time_data = {1, 7, 1, 7};
static bool is_active        = false;
static int x_pos[4];
static bool blink_state         = false;
static uint32_t last_blink_time = 0;

static void update_label_text(lv_obj_t* label, int value) {
  char buffer[2];
  snprintf(buffer, sizeof(buffer), "%d", value);
  lv_label_set_text(label, buffer);
}

static void refresh() {
  lv_obj_t** elements = nav_state->current_screen->elements;

  update_label_text(elements[0], time_data.hour1);
  update_label_text(elements[1], time_data.hour2);
  update_label_text(elements[3], time_data.min1);
  update_label_text(elements[4], time_data.min2);

  if (lv_tick_elaps(last_blink_time) >= 500) {
    last_blink_time = lv_tick_get();
    blink_state     = !blink_state;
  }

  if (is_active) {
    if (blink_state)
      lv_obj_add_flag(elements[5], LV_OBJ_FLAG_HIDDEN);
    else
      lv_obj_clear_flag(elements[5], LV_OBJ_FLAG_HIDDEN);
  } else {
    lv_obj_clear_flag(elements[5], LV_OBJ_FLAG_HIDDEN);
  }
}

static void handle_set() {
  is_active = !is_active;
}

static void handle_back() {
  menu_navigate_go_back(&nav_state);
}

static void handle_up() {
  if (!is_active) {
    update_index(DIRECTION_UP);
    lv_obj_t** elements = nav_state->current_screen->elements;
    lv_obj_set_x(elements[5], x_pos[nav_state->selected_index]);
    return;
  }

  switch (nav_state->selected_index) {
  case 0:
    time_data.hour1 = (time_data.hour1 + 2) % 3;
    if (time_data.hour1 == 2 && time_data.hour2 > 3) {
      time_data.hour2 = 3;
    }
    break;
  case 1:
    if (time_data.hour1 == 2) {
      time_data.hour2 = (time_data.hour2 + 2) % 3;
    } else {
      time_data.hour2 = (time_data.hour2 + 9) % 10;
    }
    break;
  case 2:
    time_data.min1 = (time_data.min1 + 5) % 6;
    break;
  case 3:
    time_data.min2 = (time_data.min2 + 9) % 10;
    break;
  }
  refresh();
}

static void handle_down() {
  if (!is_active) {
    update_index(DIRECTION_DOWN);
    lv_obj_t** elements = nav_state->current_screen->elements;
    lv_obj_set_x(elements[5], x_pos[nav_state->selected_index]);
    return;
  }

  switch (nav_state->selected_index) {
  case 0:
    time_data.hour1 = (time_data.hour1 + 1) % 3;
    break;
  case 1:
    time_data.hour2 = (time_data.hour2 + 1) % 10;
    break;
  case 2:
    time_data.min1 = (time_data.min1 + 1) % 6;
    break;
  case 3:
    time_data.min2 = (time_data.min2 + 1) % 10;
    break;
  }
  refresh();
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
  button_control_set_title(TEXT_ID_CLOCK);
  lv_obj_t** elements = nav_state->current_screen->elements;

  int positions[5] = {
      TIME_X_CENTER - COLON_WIDTH / 2 - 2 * FIX_WIDTH,  // hour1_x
      TIME_X_CENTER - COLON_WIDTH / 2 - FIX_WIDTH,      // hour2_x
      TIME_X_CENTER - COLON_WIDTH / 2,                  // colon_x
      TIME_X_CENTER + COLON_WIDTH / 2,                  // min1_x
      TIME_X_CENTER + COLON_WIDTH / 2 + FIX_WIDTH       // min2_x
  };

  label_color_e color = tool_get_color_base();
  label_font_e font   = LABEL_FONT_HARMONYOS_80;
  int height          = 100;

  label_pos_t label_positions[5] = {
      ui_helpers_init_label_position(positions[0], TIME_Y_POSITION, FIX_WIDTH,
                                     height, color, font, VALUE_TYPE_INT,
                                     (label_value_t)1),
      ui_helpers_init_label_position(positions[1], TIME_Y_POSITION, FIX_WIDTH,
                                     height, color, font, VALUE_TYPE_INT,
                                     (label_value_t)7),
      ui_helpers_init_label_position(positions[2], TIME_Y_POSITION, COLON_WIDTH,
                                     height, color, font, VALUE_TYPE_CHAR,
                                     (label_value_t){":"}),
      ui_helpers_init_label_position(positions[3], TIME_Y_POSITION, FIX_WIDTH,
                                     height, color, font, VALUE_TYPE_INT,
                                     (label_value_t)1),
      ui_helpers_init_label_position(positions[4], TIME_Y_POSITION, FIX_WIDTH,
                                     height, color, font, VALUE_TYPE_INT,
                                     (label_value_t)7)};

  initialize_background(&elements[5], menu_window_get(), label_positions[0].x,
                        TIME_Y_POSITION - 10, FIX_WIDTH, height - 20,
                        lv_color_make(0xFF, 0, 0));

  x_pos[0] = label_positions[0].x;
  x_pos[1] = label_positions[1].x;
  x_pos[2] = label_positions[3].x;
  x_pos[3] = label_positions[4].x;

  for (int i = 0; i < 5; ++i) {
    ui_helpers_create_label(menu_window_get(), &elements[i],
                            label_positions[i]);
    lv_obj_set_style_text_align(elements[i], LV_TEXT_ALIGN_CENTER, 0);
  }
}

static void close_window() {
}

void clock_init() {
  menu_item_t* items = (menu_item_t*)malloc(4 * sizeof(menu_item_t));
  if (!items)
    return;

  items[0] = (menu_item_t){"hour 1", -1, OPTION_NULL};
  items[1] = (menu_item_t){"hour 2", -1, OPTION_NULL};
  items[2] = (menu_item_t){"minute 1", -1, OPTION_NULL};
  items[3] = (menu_item_t){"minute 2", -1, OPTION_NULL};

  screen_t* screen =
      menu_navigate_create_screen(SETTING_CLOCK, "clock", items, 4, 10);
  menu_component_t* component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  screen->component = component;

  menu_navigate_to(&nav_state, screen);
  open_window();
}
