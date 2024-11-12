#include "settings.h"
#include "../cell.h"
#include "ui_helpers.h"
#include "preview.h"
#include "left_menu.h"
#include "menu_navigate.h"

static const int LABEL_OFFSET_Y = 60;
static const int LABEL_BASE_Y = 20;
static const int LABEL_WIDTH = 250;

typedef enum {
  SETTINGS_DEVICE_CONNECTION,
  SETTINGS_OPTION_INFO_1,
  SETTINGS_OPTION_INFO_2,
  SETTINGS_AUTO_BRIGHTNESS,
  SETTINGS_UNIT,
  SETTINGS_TIME,
  SETTINGS_CONTENT,
  SETTINGS_UPGRADE,
  SETTINGS_ABOUT,
  SETTINGS_MAIN,
  SETTINGS_COUNT,
} settings_id_t;

extern lv_obj_t* menu_window;
static lv_obj_t* elements[14] = {NULL};
static bool is_active = false;
static navigation_state_t* nav_state = NULL;

menu_item_t settings_menu_items[] = {
    {"设备连接", SETTINGS_DEVICE_CONNECTION, OPTION_PAGE},
    {"可选信息1", SETTINGS_OPTION_INFO_1, OPTION_PAGE},
    {"可选信息2", SETTINGS_OPTION_INFO_2, OPTION_PAGE},
    {"自动亮度", -1, OPTION_DROPDOWN},
    {"单位设置", -1, OPTION_DROPDOWN},
    {"时间设置", -1, OPTION_DROPDOWN},
    {"文本内容", SETTINGS_CONTENT, OPTION_PAGE},
    {"系统升级", SETTINGS_UPGRADE, OPTION_PAGE},
    {"关于本机", SETTINGS_ABOUT, OPTION_PAGE}};

// Global definition for settings screen
static screen_t settings_screen = {
    SETTINGS_MAIN, "Settings", settings_menu_items,
    sizeof(settings_menu_items) / sizeof(settings_menu_items[0])};

// Initialize navigation state and settings screen
static void init_item() {
  nav_state = malloc(sizeof(navigation_state_t));
  nav_state->current_screen = &settings_screen;
  nav_state->selected_index = 0;
  nav_state->prev = NULL;
  print_navigation_state(nav_state);
}

static void open_window();

static void refresh() {}

static void handle_click_up(const click_t click) {
  if (nav_state->current_screen->id == SETTINGS_MAIN) {
    nav_state->selected_index =
        (nav_state->selected_index == 0)
            ? (nav_state->current_screen->menu_item_count - 1)
            : (nav_state->selected_index - 1);
  }
}

static void handle_click_down(const click_t click) {
  if (nav_state->current_screen->id == SETTINGS_MAIN) {
    nav_state->selected_index = (nav_state->selected_index + 1) %
                                nav_state->current_screen->menu_item_count;
  }
}

static bool handle_click_event(const click_t click) {
  switch (click) {
    case CLICK_SHORT_SET:
      if (!is_active) {
        is_active = true;
        open_window();
      } else {
        if (nav_state->current_screen->id == SETTINGS_MAIN) {
          switch (nav_state->selected_index) {
            case SETTINGS_DEVICE_CONNECTION:
              break;
          }
        }
      }
      break;
    case CLICK_SHORT_BACK:
      is_active = false;
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

static void toggle_day_night() {}
static void destroy() {
  if (nav_state) {
    free(nav_state);
    nav_state = NULL;
  }
}

static void prepare_window() {
  left_menu_show(false);
  preview_close();
}

static void setup_label(lv_obj_t* window, lv_obj_t** element1,
                        lv_obj_t** element2, int y_offset, int text_id,
                        const char* img_path, const char* text) {
  label_params_t params = ui_helpers_settings_params(
      LABEL_WIDTH, y_offset, lang_text(text_id), img_path, text);
  ui_helpers_component(window, element1, element2, params);
}

static void open_window() {
  init_item();
  prepare_window();

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
}

static void close_window() {}

menu_component_t* settings() {
  menu_component_t* component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  return component;
}

void settings_device() {

}

void settings_option1() {}
void settings_option2() {}
void settings_content() {}
void settings_upgrade() {}
void settings_about() {}
