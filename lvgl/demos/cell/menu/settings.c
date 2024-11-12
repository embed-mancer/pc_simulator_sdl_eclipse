#include "settings.h"
#include "../cell.h"
#include "ui_helpers.h"
#include "preview.h"
#include "left_menu.h"

static const int LABEL_OFFSET_Y = 60;
static const int LABEL_BASE_Y = 20;
static const int LABEL_WIDTH = 250;

extern lv_obj_t* menu_window;

static lv_obj_t* elements[14] = {NULL};
static bool is_active = false;

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
    case CLICK_SHORT_UP:
      break;
    case CLICK_SHORT_DOWN:
      break;
    default:
      return false;
  }
  return is_active;
}

static void toggle_day_night() {}

static void destroy() {}

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
