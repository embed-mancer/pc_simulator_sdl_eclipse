#include "settings.h"
#include "../cell.h"
#include "ui_helpers.h"
#include "preview.h"
#include "left_menu.h"

static bool is_active = false;
extern lv_obj_t* menu_window;

static lv_obj_t* elements[14] = {NULL};

static void open_window();

static void refresh() {}

static bool handle_click_event(const click_t click) {
  switch (click) {
    case CLICK_SHORT_SET:
      is_active = true;
      open_window();
      break;
    case CLICK_SHORT_BACK:
      is_active = false;
      break;
    case CLICK_LONG_SET:
      break;
    case CLICK_LONG_BACK:
      break;
    default:
      return false;
  }
  if (!is_active) return false;
  return true;
}

static void toggle_day_night() {}

static void destroy() {}

static void open_window() {
  left_menu_show(false);
  preview_close();
  label_params_t params_connection =
      ui_helpers_settings_params(250, 20, lang_text(TEXT_ID_DEVICE_CONNECTION),
                        RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window, &elements[0], &elements[1],
                       params_connection);
  label_params_t params_option_1 = ui_helpers_settings_params(
      250, 80, lang_text(TEXT_ID_OPTIONAL_INFO_1), RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window, &elements[2], &elements[3],
                       params_option_1);
  label_params_t params_option_2 = ui_helpers_settings_params(
      250, 140, lang_text(TEXT_ID_OPTIONAL_INFO_2), RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window, &elements[4], &elements[5],
                       params_option_2);
  label_params_t params_auto =
      ui_helpers_settings_params(250, 200, lang_text(TEXT_ID_AUTO_BRIGHTNESS), NULL,
                        lang_text(TEXT_ID_OPEN));
  ui_helpers_component(menu_window, &elements[6], &elements[7], params_auto);
  label_params_t params_unit = ui_helpers_settings_params(
      250, 260, lang_text(TEXT_ID_UNIT_SETTINGS), RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window, &elements[8], &elements[9], params_unit);
  label_params_t params_time = ui_helpers_settings_params(
      250, 320, lang_text(TEXT_ID_TIME_SETTINGS), RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window, &elements[10], &elements[11], params_time);
  label_params_t params_language =
      ui_helpers_settings_params(250, 380, lang_text(TEXT_ID_LANGUAGE_SETTINGS),
                        RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window, &elements[12], &elements[13],
                       params_language);
}

static void close_window() {}

menu_component_t* settings() {
  menu_component_t* component = allocate_component();
  init_component(component, refresh, handle_click_event, toggle_day_night,
                 destroy, open_window, close_window);
  return component;
}
