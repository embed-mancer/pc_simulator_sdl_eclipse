#include "menu_navigate.h"

extern void basic_info();
extern void odo_info();
extern void trip_info();
extern void fault_info();

static bool is_active = true;
#define VEHICLE_COUNT 5

static int y_pos[VEHICLE_COUNT];

static void refresh() {
}

typedef void (*click_handler_t)(void);

static void handle_set() {
  switch (nav_state->selected_index) {
  case 0:
    basic_info();
    break;
  case 1:
    odo_info();
    break;
  case 2:
    trip_info();
    break;
  case 3:
    fault_info();
    break;
  }
}

static void handle_back() {
  menu_navigate_go_back(&nav_state);
}

static void handle_up() {
  update_index(DIRECTION_UP);
  lv_obj_t** elements = nav_state->current_screen->elements;
  lv_obj_set_y(elements[19], y_pos[nav_state->selected_index]);
}

static void handle_down() {
  update_index(DIRECTION_DOWN);
  lv_obj_t** elements = nav_state->current_screen->elements;
  lv_obj_set_y(elements[19], y_pos[nav_state->selected_index]);
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
  button_control_set_title(TEXT_ID_VEHICLE);
  lv_obj_t** elements = nav_state->current_screen->elements;

  label_color_e color      = tool_get_color_base();

  for (size_t i = 0; i < VEHICLE_COUNT; ++i) y_pos[i] = 70 + 68 * i;

  ui_helpers_menu_image(elements, "selected.png", 19, 292, y_pos[0]);

  ui_helpers_menu_image(elements, "icon_basic.png", 1, 301, 77);
  ui_helpers_menu_image(elements, "arrow_down.png", 2, 755, y_pos[0] + 20);
  ui_helpers_menu_image(elements, "icon_odo.png", 3, 295, 147);
  ui_helpers_menu_image(elements, "arrow_down.png", 4, 755, y_pos[1] + 20);
  ui_helpers_menu_image(elements, "icon_trip.png", 5, 295, 215);
  ui_helpers_menu_image(elements, "arrow_down.png", 6, 755, y_pos[2] + 20);
  ui_helpers_menu_image(elements, "icon_fault.png", 7, 293, 284);
  ui_helpers_menu_image(elements, "arrow_down.png", 8, 755, y_pos[3] + 20);
  ui_helpers_menu_image(elements, "icon_maintain.png", 9, 297, 351);
  ui_helpers_menu_image(elements, "arrow_down.png", 10, 755, y_pos[4] + 20);

  ui_helpers_create_label_left(menu_window_get(), &elements[11], 345, y_pos[0],
                               300, 48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_BASIC));
  ui_helpers_create_label_left(menu_window_get(), &elements[12], 345, y_pos[1],
                               300, 48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_ODO));
  ui_helpers_create_label_left(menu_window_get(), &elements[13], 345, y_pos[2],
                               300, 48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_TRIP));
  ui_helpers_create_label_left(menu_window_get(), &elements[14], 345, y_pos[3],
                               300, 48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_FAULT_INFO));
  ui_helpers_create_label_left(menu_window_get(), &elements[15], 345, y_pos[4],
                               300, 48, color, LABEL_FONT_HARMONYOS_24,
                               lang_text(TEXT_ID_MAINTAIN));
}

static void close_window() {
}

void vehicle_init() {
  menu_item_t* items =
      (menu_item_t*)malloc(VEHICLE_COUNT * sizeof(menu_item_t));
  if (!items)
    return;

  items[0] = (menu_item_t){"basic info", -1, OPTION_NULL};
  items[1] = (menu_item_t){"ODO info", -1, OPTION_NULL};
  items[2] = (menu_item_t){"TRIP info", -1, OPTION_NULL};
  items[3] = (menu_item_t){"fault info", -1, OPTION_NULL};
  items[4] = (menu_item_t){"maintain", -1, OPTION_NULL};

  screen_t* screen = menu_navigate_create_screen(SETTING_VEHICLE, "vehicle",
                                                 items, VEHICLE_COUNT, 20);
  menu_component_t* component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  screen->component = component;

  menu_navigate_to(&nav_state, screen);
  open_window();
}
