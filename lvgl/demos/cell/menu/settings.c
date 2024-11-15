#include "settings.h"
#include "../cell.h"
#include "ui_helpers.h"
#include "preview.h"
#include "side_bar.h"
#include "menu_navigate.h"

static const int LABEL_OFFSET_Y = 60;
static const int LABEL_BASE_Y   = 20;
static const int LABEL_WIDTH    = 250;
static const int ELEMENTS_COUNT = 14;

typedef enum {
  SETTINGS_DEVICE_CONNECTION,
  SETTINGS_OPTION_INFO_1,
  SETTINGS_OPTION_INFO_2,
  SETTINGS_AUTO_BRIGHTNESS,
  SETTINGS_UNIT,
  SETTINGS_TIME,
  SETTINGS_LANGUAGE,
  SETTINGS_UPGRADE,
  SETTINGS_ABOUT,
  SETTINGS_PREVIEW,
  SETTINGS_MAIN,
  // device
  SETTINGS_MOBLIE_DEVICE,
  SETTINGS_HELMET1,
  SETTINGS_HELMET2,
  // option 1
  SETTINGS_OPTION_1_ODO,
  SETTINGS_OPTION_1_TRIP1,
  SETTINGS_OPTION_1_TRIP2,
  // option2
  SETTINGS_OPTION_2_RANGE,
  SETTINGS_OPTION_2_VOLTAGE,
  SETTINGS_OPTION_2_INSTANT_FUEL,
  SETTINGS_OPTION_2_TRIP_TIME,
  SETTINGS_OPTION_2_AVERAGE_FUEL,
  SETTINGS_OPTION_2_AVERAGE_SPEED,
  SETTINGS_COUNT,
} settings_id_e;

extern lv_obj_t* menu_window;
static bool is_active                = false;
static navigation_state_t* nav_state = NULL;

static void setup_label(lv_obj_t* window, lv_obj_t** element1,
                        lv_obj_t** element2, int y_offset, int text_id,
                        const char* img_path, const char* text) {
  label_params_t params = ui_helpers_settings_params(
      LABEL_WIDTH, y_offset, lang_text(text_id), img_path, text);
  ui_helpers_component(window, element1, element2, params);
}

static void settings_enter() {
  side_bar_show(false);
  menu_item_t* items = malloc(9 * sizeof(menu_item_t));
  if (!items)
    return;

  items[SETTINGS_DEVICE_CONNECTION] = (menu_item_t){
      "device connection", SETTINGS_DEVICE_CONNECTION, OPTION_PAGE};
  items[SETTINGS_OPTION_INFO_1] =
      (menu_item_t){"option info 1", SETTINGS_OPTION_INFO_1, OPTION_PAGE};
  items[SETTINGS_OPTION_INFO_2] =
      (menu_item_t){"option info 2", SETTINGS_OPTION_INFO_2, OPTION_PAGE};
  items[SETTINGS_AUTO_BRIGHTNESS] =
      (menu_item_t){"auto brightness", -1, OPTION_DROPDOWN};
  items[SETTINGS_UNIT] = (menu_item_t){"unit settings", -1, OPTION_DROPDOWN};
  items[SETTINGS_TIME] = (menu_item_t){"time settings", -1, OPTION_DROPDOWN};
  items[SETTINGS_LANGUAGE] =
      (menu_item_t){"language settings", -1, OPTION_PAGE};
  items[SETTINGS_UPGRADE] =
      (menu_item_t){"upgrade", SETTINGS_UPGRADE, OPTION_PAGE};
  items[SETTINGS_ABOUT] = (menu_item_t){"about", SETTINGS_ABOUT, OPTION_PAGE};

  screen_t* screen =
      menu_navigate_create_screen(SETTINGS_MAIN, "Settings", items, 9, 20);

  lv_obj_t** elements = screen->elements;
  setup_label(menu_window, &elements[0], &elements[1], LABEL_BASE_Y,
              TEXT_ID_DEVICE_CONNECTION, RIGHT_ARROW_IMG_PATH, NULL);
  setup_label(menu_window, &elements[2], &elements[3],
              LABEL_BASE_Y + LABEL_OFFSET_Y, TEXT_ID_OPTIONAL_INFO_1,
              RIGHT_ARROW_IMG_PATH, NULL);
  setup_label(menu_window, &elements[4], &elements[5],
              LABEL_BASE_Y + 2 * LABEL_OFFSET_Y, TEXT_ID_OPTIONAL_INFO_2,
              RIGHT_ARROW_IMG_PATH, NULL);
  setup_label(menu_window, &elements[6], &elements[7],
              LABEL_BASE_Y + 3 * LABEL_OFFSET_Y, TEXT_ID_AUTO_BRIGHTNESS, NULL,
              lang_text(TEXT_ID_OPEN));
  setup_label(menu_window, &elements[8], &elements[9],
              LABEL_BASE_Y + 4 * LABEL_OFFSET_Y, TEXT_ID_UNIT_SETTINGS,
              RIGHT_ARROW_IMG_PATH, NULL);
  setup_label(menu_window, &elements[10], &elements[11],
              LABEL_BASE_Y + 5 * LABEL_OFFSET_Y, TEXT_ID_TIME_SETTINGS,
              RIGHT_ARROW_IMG_PATH, NULL);
  setup_label(menu_window, &elements[12], &elements[13],
              LABEL_BASE_Y + 6 * LABEL_OFFSET_Y, TEXT_ID_LANGUAGE_SETTINGS,
              RIGHT_ARROW_IMG_PATH, NULL);

  nav_state = menu_navigate_to(nav_state, screen);
}

static void settings_device_connection() {
  menu_item_t* items = malloc(3 * sizeof(menu_item_t));
  if (!items)
    return;

  items[0] =
      (menu_item_t){"mobile device", SETTINGS_MOBLIE_DEVICE, OPTION_PAGE};
  items[1] = (menu_item_t){"helmet 1", SETTINGS_HELMET1, OPTION_PAGE};
  items[2] = (menu_item_t){"helmet 2", SETTINGS_HELMET2, OPTION_PAGE};

  screen_t* screen = menu_navigate_create_screen(
      SETTINGS_DEVICE_CONNECTION, "device connection", items, 3, 10);
  nav_state = menu_navigate_to(nav_state, screen);
}

static void settings_mobile_device() {
  menu_item_t* items = malloc(3 * sizeof(menu_item_t));
  if (!items)
    return;

  items[0] = (menu_item_t){"device 1 ", -1, OPTION_NULL};
  items[1] = (menu_item_t){"device 2", -1, OPTION_NULL};
  items[2] = (menu_item_t){"device 3 ", -1, OPTION_NULL};

  screen_t* screen = menu_navigate_create_screen(SETTINGS_MOBLIE_DEVICE,
                                                 "mobile device", items, 3, 10);
  nav_state        = menu_navigate_to(nav_state, screen);
}

static void settings_helmet1() {
  menu_item_t* items = malloc(3 * sizeof(menu_item_t));
  if (!items)
    return;

  items[0] = (menu_item_t){"device 1 ", -1, OPTION_NULL};
  items[1] = (menu_item_t){"device 2", -1, OPTION_NULL};
  items[2] = (menu_item_t){"device 3 ", -1, OPTION_NULL};

  screen_t* screen =
      menu_navigate_create_screen(SETTINGS_HELMET1, "helmet 1", items, 3, 10);
  nav_state = menu_navigate_to(nav_state, screen);
}

static void settings_helmet2() {
  menu_item_t* items = malloc(3 * sizeof(menu_item_t));
  if (!items)
    return;

  items[0] = (menu_item_t){"device 1 ", -1, OPTION_NULL};
  items[1] = (menu_item_t){"device 2", -1, OPTION_NULL};
  items[2] = (menu_item_t){"device 3 ", -1, OPTION_NULL};

  screen_t* screen =
      menu_navigate_create_screen(SETTINGS_HELMET2, "helmet 2", items, 3, 10);
  nav_state = menu_navigate_to(nav_state, screen);
}

static void settings_option1() {
  menu_item_t* items = malloc(3 * sizeof(menu_item_t));
  if (!items)
    return;

  items[0] = (menu_item_t){"ODO", -1, OPTION_RADIO};
  items[1] = (menu_item_t){"TRIP1", -1, OPTION_RADIO};
  items[2] = (menu_item_t){"TRIP2", -1, OPTION_RADIO};

  screen_t* screen = menu_navigate_create_screen(SETTINGS_OPTION_INFO_1,
                                                 "Option 1", items, 3, 10);
  nav_state        = menu_navigate_to(nav_state, screen);
}

static void settings_option2() {
  menu_item_t* items = malloc(6 * sizeof(menu_item_t));
  if (!items)
    return;

  items[0] = (menu_item_t){"range", -1, OPTION_RADIO};
  items[1] = (menu_item_t){"voltage", -1, OPTION_RADIO};
  items[2] = (menu_item_t){"instant fuel", -1, OPTION_RADIO};
  items[3] = (menu_item_t){"trip time", -1, OPTION_RADIO};
  items[4] = (menu_item_t){"avg fuel", -1, OPTION_RADIO};
  items[5] = (menu_item_t){"avg speed", -1, OPTION_RADIO};

  screen_t* screen = menu_navigate_create_screen(SETTINGS_OPTION_INFO_2,
                                                 "Option 2", items, 6, 10);

  nav_state = menu_navigate_to(nav_state, screen);
}

static void settings_auto_brightness() {
  screen_t* screen = menu_navigate_create_screen(
      SETTINGS_AUTO_BRIGHTNESS, "auto brightness", NULL, 0, 10);
  nav_state = menu_navigate_to(nav_state, screen);
}

static void settings_unit() {
  screen_t* screen =
      menu_navigate_create_screen(SETTINGS_UNIT, "unit settings", NULL, 0, 10);
  nav_state = menu_navigate_to(nav_state, screen);
}

static void settings_time() {
  screen_t* screen =
      menu_navigate_create_screen(SETTINGS_TIME, "time settings", NULL, 0, 10);
  nav_state = menu_navigate_to(nav_state, screen);
}

static void settings_language() {
  menu_item_t* items = malloc(2 * sizeof(menu_item_t));
  if (!items)
    return;

  items[0] = (menu_item_t){"Chinese", -1, OPTION_RADIO};
  items[1] = (menu_item_t){"English", -1, OPTION_RADIO};

  screen_t* screen =
      menu_navigate_create_screen(SETTINGS_LANGUAGE, "Language", items, 2, 10);

  nav_state = menu_navigate_to(nav_state, screen);
}

static void settings_upgrade() {
  menu_item_t* items = malloc(2 * sizeof(menu_item_t));
  if (!items)
    return;

  items[0] = (menu_item_t){"wifi 1", -1, OPTION_RADIO};
  items[1] = (menu_item_t){"wifi 2", -1, OPTION_RADIO};

  screen_t* screen =
      menu_navigate_create_screen(SETTINGS_UPGRADE, "network", items, 2, 10);
  nav_state = menu_navigate_to(nav_state, screen);
}

static void settings_about() {
  screen_t* screen =
      menu_navigate_create_screen(SETTINGS_ABOUT, "about", NULL, 0, 10);
  nav_state = menu_navigate_to(nav_state, screen);
}

static void refresh() {
}

static void handle_click_up(const click_e click) {
  if (!is_active)
    return;
  if (nav_state->current_screen->id == SETTINGS_MAIN) {
    nav_state->selected_index =
        (nav_state->selected_index == 0)
            ? (nav_state->current_screen->menu_item_count - 1)
            : (nav_state->selected_index - 1);
  }
  if (nav_state->current_screen->id == SETTINGS_OPTION_INFO_1 ||
      nav_state->current_screen->id == SETTINGS_OPTION_INFO_2) {
    nav_state->selected_index =
        (nav_state->selected_index == 0)
            ? (nav_state->current_screen->menu_item_count - 1)
            : (nav_state->selected_index - 1);
  }
}

static void handle_click_down(const click_e click) {
  if (!is_active)
    return;
  if (nav_state->current_screen->id == SETTINGS_MAIN) {
    nav_state->selected_index = (nav_state->selected_index + 1) %
                                nav_state->current_screen->menu_item_count;
  }
  if (nav_state->current_screen->id == SETTINGS_OPTION_INFO_1 ||
      nav_state->current_screen->id == SETTINGS_OPTION_INFO_2) {
    nav_state->selected_index = (nav_state->selected_index + 1) %
                                nav_state->current_screen->menu_item_count;
  }
}

static void handle_click_set(const click_e click) {
  if (!is_active) {
    is_active = true;
    settings_enter();
    return;
  }
  if (nav_state->current_screen->id == SETTINGS_MAIN) {
    switch (nav_state->selected_index) {
    case SETTINGS_DEVICE_CONNECTION:
      settings_device_connection();
      break;
    case SETTINGS_OPTION_INFO_1:
      settings_option1();
      break;
    case SETTINGS_OPTION_INFO_2:
      settings_option2();
      break;
    case SETTINGS_AUTO_BRIGHTNESS:
      settings_auto_brightness();
      break;
    case SETTINGS_UNIT:
      settings_unit();
      break;
    case SETTINGS_TIME:
      settings_time();
      break;
    case SETTINGS_LANGUAGE:
      settings_language();
      break;
    case SETTINGS_UPGRADE:
      settings_upgrade();
      break;
    case SETTINGS_ABOUT:
      settings_about();
      break;
    case SETTINGS_MOBLIE_DEVICE:
      settings_mobile_device();
      break;
    case SETTINGS_HELMET1:
      settings_helmet1();
      break;
    case SETTINGS_HELMET2:
      settings_helmet2();
      break;
    }
  }
}

static void handle_click_back(const click_e click) {
  switch (nav_state->current_screen->id) {
  case SETTINGS_DEVICE_CONNECTION:
  case SETTINGS_OPTION_INFO_1:
  case SETTINGS_OPTION_INFO_2:
  case SETTINGS_AUTO_BRIGHTNESS:
  case SETTINGS_UNIT:
  case SETTINGS_TIME:
  case SETTINGS_LANGUAGE:
  case SETTINGS_UPGRADE:
  case SETTINGS_ABOUT:
    nav_state = menu_navigate_go_back(nav_state);
    break;
  case SETTINGS_MAIN:
    nav_state = menu_navigate_go_back(nav_state);
    is_active = false;
    break;
  }
}

static bool handle_click_event(const click_e click) {
  switch (click) {
  case CLICK_SHORT_SET:
    handle_click_set(click);
    break;
  case CLICK_SHORT_BACK:
    handle_click_back(click);
    break;
  case CLICK_SHORT_UP:
    handle_click_up(click);
    break;
  case CLICK_SHORT_DOWN:
    handle_click_down(click);
    break;
  default:
    return false;
  }
  print_navigation_state(nav_state);
  return is_active;
}

static void toggle_day_night() {
}

static void destroy() {
  menu_navigate_free(nav_state);
}

static void open_window() {
  screen_t* screen = menu_navigate_create_screen(
      SETTINGS_PREVIEW, "settings preview", NULL, 0, 20);
  preview_settings(screen->elements);
  nav_state = menu_navigate_create(screen);
}

static void close_window() {
}

menu_component_t* settings() {
  menu_component_t* component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  return component;
}
