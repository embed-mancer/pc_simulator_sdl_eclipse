#include "vehicle_settings.h"
#include "../cell.h"
#include "ui_helpers.h"
#include "preview.h"
#include "side_bar.h"
#include "menu_navigate.h"
#include "../language/lang.h"
#include "../config/config.h"

typedef enum {
  VEHICLE_INFO,
  VEHICLE_TC,
  VEHICLE_ESS,
  VEHICLE_QUICK_SHIFT,
  VEHICLE_UP_SHIFT,
  VEHICLE_BASIC_INFO,
  VEHICLE_ODO_INFO,
  VEHICLE_TRIP_INFO,
  VEHICLE_FAULT_INFO,
  VEHICLE_MAINTAIN,

  VEHICLE_MAIN,
} vehicle_e;

static item_t* items[5];
static bool is_active = false;
static navigation_state_t* nav_state = NULL;
extern lv_obj_t* menu_window;

static void settings() {
  side_bar_show(false);
  menu_item_t* items = malloc(5 * sizeof(menu_item_t));
  if (!items) return;

  items[0] = (menu_item_t){"vehicle info", VEHICLE_INFO, OPTION_PAGE};
  items[1] = (menu_item_t){"TC", -1, OPTION_NULL};
  items[2] = (menu_item_t){"ESS", -1, OPTION_NULL};
  items[3] = (menu_item_t){"quick shift", -1, OPTION_NULL};
  items[4] = (menu_item_t){"up shift", -1, OPTION_NULL};

  screen_t* screen = menu_navigate_create_screen(
      VEHICLE_MAIN, "vehicle settings main", items, 5, 20);

  lv_obj_t** elements = screen->elements;
  create_center_left_label(menu_window, &elements[0], 20, 70, 350, 60,
                           LABEL_COLOR_WHITE, LABEL_FONT_MICROSOFT_YAHEI_18,
                           lang_text(TEXT_ID_VEHICLE_INFO));
  image_pos_t arrow_pos = create_image_pos("", 400, 80);
  create_img(menu_window, &elements[1], arrow_pos);

  create_center_left_label(menu_window, &elements[2], 20, 130, 350, 60,
                           LABEL_COLOR_WHITE, LABEL_FONT_MICROSOFT_YAHEI_18,
                           "TC");
  create_center_right_label(menu_window, &elements[3], 300, 130, 100, 60,
                            LABEL_COLOR_WHITE, LABEL_FONT_MICROSOFT_YAHEI_18,
                            lang_text(TEXT_ID_CLOSE));

  create_center_left_label(menu_window, &elements[4], 20, 190, 350, 60,
                           LABEL_COLOR_WHITE, LABEL_FONT_MICROSOFT_YAHEI_18,
                           "ESS");
  create_center_right_label(menu_window, &elements[5], 300, 190, 100, 60,
                            LABEL_COLOR_WHITE, LABEL_FONT_MICROSOFT_YAHEI_18,
                            lang_text(TEXT_ID_CLOSE));

  create_center_left_label(menu_window, &elements[6], 20, 250, 350, 60,
                           LABEL_COLOR_WHITE, LABEL_FONT_MICROSOFT_YAHEI_18,
                           lang_text(TEXT_ID_QUICK_SHIFT));
  create_center_right_label(menu_window, &elements[7], 300, 250, 100, 60,
                            LABEL_COLOR_WHITE, LABEL_FONT_MICROSOFT_YAHEI_18,
                            lang_text(TEXT_ID_CLOSE));

  create_center_left_label(menu_window, &elements[8], 20, 310, 350, 60,
                           LABEL_COLOR_WHITE, LABEL_FONT_MICROSOFT_YAHEI_18,
                           lang_text(TEXT_ID_UPSHIFT));
  create_center_right_label(menu_window, &elements[9], 300, 310, 100, 60,
                            LABEL_COLOR_WHITE, LABEL_FONT_MICROSOFT_YAHEI_18,
                            lang_text(TEXT_ID_CLOSE));

  nav_state = menu_navigate_to(nav_state, screen);
  // TODO title and image
}

static void info() {
  menu_item_t* items = malloc(5 * sizeof(menu_item_t));
  if (!items) return;

  items[0] = (menu_item_t){"basic info", -1, OPTION_NULL};
  items[1] = (menu_item_t){"odo info", -1, OPTION_NULL};
  items[2] = (menu_item_t){"trip info", -1, OPTION_NULL};
  items[3] = (menu_item_t){"fault info", -1, OPTION_NULL};
  items[4] = (menu_item_t){"maintain", -1, OPTION_NULL};

  screen_t* screen =
      menu_navigate_create_screen(VEHICLE_INFO, "vehicle info", items, 5, 20);

  lv_obj_t** elements = screen->elements;
  create_center_left_label(menu_window, &elements[0], 250, 20, 400, 60,
                           LABEL_COLOR_WHITE, LABEL_FONT_MICROSOFT_YAHEI_18,
                           lang_text(TEXT_ID_BASIC_INFO));
  create_center_left_label(menu_window, &elements[1], 250, 80, 400, 60,
                           LABEL_COLOR_WHITE, LABEL_FONT_MICROSOFT_YAHEI_18,
                           lang_text(TEXT_ID_ODO));
  create_center_left_label(menu_window, &elements[2], 250, 140, 400, 60,
                           LABEL_COLOR_WHITE, LABEL_FONT_MICROSOFT_YAHEI_18,
                           lang_text(TEXT_ID_TRIP));
  create_center_left_label(menu_window, &elements[3], 250, 200, 400, 60,
                           LABEL_COLOR_WHITE, LABEL_FONT_MICROSOFT_YAHEI_18,
                           lang_text(TEXT_ID_FAULT_INFO));
  create_center_left_label(menu_window, &elements[4], 250, 260, 400, 60,
                           LABEL_COLOR_WHITE, LABEL_FONT_MICROSOFT_YAHEI_18,
                           lang_text(TEXT_ID_MAINTAIN_MILEAGE));
  nav_state = menu_navigate_to(nav_state, screen);
  // TODO left icon and title
}

static void basic_info() {
  screen_t* screen = menu_navigate_create_screen(
      VEHICLE_BASIC_INFO, "vehicle basic info", NULL, 0, 20);

  lv_obj_t** elements = screen->elements;
  nav_state = menu_navigate_to(nav_state, screen);
}

static void odo_info() {
  screen_t* screen = menu_navigate_create_screen(
      VEHICLE_ODO_INFO, "vehicle odo info", NULL, 0, 20);

  lv_obj_t** elements = screen->elements;
  nav_state = menu_navigate_to(nav_state, screen);
}

static void trip_info() {
  menu_item_t* items = malloc(2 * sizeof(menu_item_t));
  if (!items) return;

  items[0] = (menu_item_t){"trip 1", -1, OPTION_NULL};
  items[1] = (menu_item_t){"trip 2", -1, OPTION_NULL};

  screen_t* screen = menu_navigate_create_screen(
      VEHICLE_TRIP_INFO, "vehicle trip info", items, 2, 20);

  lv_obj_t** elements = screen->elements;
  nav_state = menu_navigate_to(nav_state, screen);
}

static void fault_info() {
  // TODO according to the actual number of faults
  menu_item_t* items = malloc(2 * sizeof(menu_item_t));
  if (!items) return;

  items[0] = (menu_item_t){"fault 1", -1, OPTION_NULL};
  items[1] = (menu_item_t){"fault 2", -1, OPTION_NULL};

  screen_t* screen = menu_navigate_create_screen(
      VEHICLE_FAULT_INFO, "vehicle fault info", items, 2, 20);

  lv_obj_t** elements = screen->elements;
  nav_state = menu_navigate_to(nav_state, screen);
}

static void refresh() {}

static void handle_set() {
  if (!is_active) {
    is_active = true;
    settings();
    return;
  }
  screen_t* screen = nav_state->current_screen;
  int index = nav_state->selected_index;

  if (screen->id == VEHICLE_MAIN) {
    switch (index) {
      case VEHICLE_INFO:
        info();
        break;
      case VEHICLE_TC:
        break;
      case VEHICLE_ESS:
        break;
      case VEHICLE_QUICK_SHIFT:
        break;
      case VEHICLE_UP_SHIFT:
        break;
    }
  } else if (screen->id == VEHICLE_INFO) {
    switch (index) {
      case VEHICLE_BASIC_INFO - VEHICLE_BASIC_INFO:
        basic_info();
        break;
      case VEHICLE_ODO_INFO - VEHICLE_BASIC_INFO:
        odo_info();
        break;
      case VEHICLE_TRIP_INFO - VEHICLE_BASIC_INFO:
        trip_info();
        break;
      case VEHICLE_FAULT_INFO - VEHICLE_BASIC_INFO:
        fault_info();
        break;
      case VEHICLE_MAINTAIN - VEHICLE_BASIC_INFO:
        break;
    }
  }
}

static void handle_back() {
  switch (nav_state->current_screen->id) {
    case VEHICLE_INFO:
    case VEHICLE_BASIC_INFO:
    case VEHICLE_ODO_INFO:
    case VEHICLE_TRIP_INFO:
    case VEHICLE_FAULT_INFO:
      nav_state = menu_navigate_go_back(nav_state);
      break;
    case VEHICLE_MAIN:
      is_active = false;
      nav_state = menu_navigate_go_back(nav_state);
      break;
  }
}

static void update_index(int direction) {
  screen_t* screen = nav_state->current_screen;
  int* index = &nav_state->selected_index;

  if (direction == DIRECTION_DOWN) {  // Handle down
    *index = (*index + 1) % screen->menu_item_count;
  } else if (direction == DIRECTION_UP) {  // Handle up
    *index = (*index == 0) ? screen->menu_item_count - 1
                           : (*index - 1) % screen->menu_item_count;
  }
}

static void handle_up() {
  if (!is_active) return;

  screen_t* screen = nav_state->current_screen;
  int* index = &nav_state->selected_index;

  switch (screen->id) {
    case VEHICLE_MAIN:
      update_index(DIRECTION_UP);
      // TODO
      break;
    case VEHICLE_INFO:
      update_index(DIRECTION_UP);
      // TODO
      break;
    case VEHICLE_ODO_INFO:
      update_index(DIRECTION_UP);
      // TODO
      break;
    case VEHICLE_TRIP_INFO:
      update_index(DIRECTION_UP);
      // TODO
      break;
    case VEHICLE_FAULT_INFO:
      update_index(DIRECTION_UP);
      // TODO
      break;
  }
}

static void handle_down() {
  if (!is_active) return;

  screen_t* screen = nav_state->current_screen;
  int* index = &nav_state->selected_index;

  switch (screen->id) {
    case VEHICLE_MAIN:
      update_index(DIRECTION_DOWN);
      // TODO
      break;
    case VEHICLE_INFO:
      update_index(DIRECTION_DOWN);
      // TODO
      break;
    case VEHICLE_ODO_INFO:
      update_index(DIRECTION_DOWN);
      // TODO
      break;
    case VEHICLE_TRIP_INFO:
      update_index(DIRECTION_DOWN);
      // TODO
      break;
    case VEHICLE_FAULT_INFO:
      update_index(DIRECTION_DOWN);
      // TODO
      break;
  }
}

static bool handle_click_event(const click_e click) {
  switch (click) {
    case CLICK_SHORT_SET:
      handle_set();
      break;
    case CLICK_SHORT_BACK:
      handle_back();
      break;
    case CLICK_SHORT_UP:
      handle_up();
      break;
    case CLICK_SHORT_DOWN:
      handle_down();
      break;
    default:
      return false;
  }
  print_navigation_state(nav_state);
  return is_active;
}

static void toggle_day_night() {}

static void destroy() { menu_navigate_free(nav_state); }

static void reset_items() {
  for (int i = 0; i < 5; ++i) items[i] = NULL;
}

static void open_window() {
  screen_t* screen =
      menu_navigate_create_screen(0, "vehicle preview", NULL, 0, 20);
  preview_set_vehicle_details(screen->elements);
  nav_state = menu_navigate_create(screen);
  return;
  reset_items();
  create_item(&items[0], 10, TEXT_ID_BASIC_INFO, NULL, true);
  create_item(&items[1], 80, TEXT_ID_ODO, NULL, true);
  create_item(&items[2], 150, TEXT_ID_TRIP, NULL, true);
  create_item(&items[3], 220, TEXT_ID_FAULT_INFO, "2条", true);
  create_item(&items[4], 290, TEXT_ID_MAINTAIN_MILEAGE, "500km", false);
  set_item_color(&items[0], true);
}

static void close_window() {}

menu_component_t* vehicle_settings() {
  menu_component_t* component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  return component;
}
