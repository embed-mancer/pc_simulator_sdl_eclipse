#include "preview.h"
#include "../cell.h"
#include "ui_helpers.h"

extern lv_obj_t *menu_window;
static lv_obj_t *title = NULL;
static lv_obj_t *line = NULL;

#define ELEMENTS_COUNT 12
#define RIGHT_ARROW_IMG_PATH (RES_PRFIX "menu/right_arrow.png")

typedef void (*page_handler_t)(void);
static lv_obj_t *elements[ELEMENTS_COUNT] = {NULL};

static void handle_default_page() {}
static const page_handler_t page_handlers[] = {
    preview_set_vehicle_details, preview_phone, preview_music,
    preview_navigation, preview_settings};

void preview_init(page_t page) {}

void preview_clear_elements() {
  for (int i = 0; i < ELEMENTS_COUNT; ++i) {
    if (elements[i]) {
      lv_obj_del(elements[i]);
      elements[i] = NULL;
    }
  }
}

static void clear_title_and_line() {
  if (title) {
    lv_obj_del(title);
    title = NULL;
  }
  if (line) {
    lv_obj_del(line);
    line = NULL;
  }
}

void preview_switch(page_t page) {
  clear_title_and_line();
  preview_clear_elements();

  preview_set_common_elements(page);
  if (page < sizeof(page_handlers) / sizeof(page_handler_t)) {
    page_handlers[page]();
  } else {
    handle_default_page();
  }
}

void preview_set_common_elements(page_t page) {
  const char *text;
  switch (page) {
    case PAGE_VEHICLE_SETTINGS:
      text = lang_text(TEXT_ID_VEHICLE_SETTINGS);
      break;
    case PAGE_PHONE:
      text = lang_text(TEXT_ID_PHONE);
      break;
    case PAGE_MUSIC:
      text = lang_text(TEXT_ID_MUSIC);
      break;
    case PAGE_NAVIGATION:
      text = "MotoPlay";
      break;
    case PAGE_SETTINGS:
      text = lang_text(TEXT_ID_SETTINGS);
      break;
    default:
      return;
  }
  create_center_left_label(menu_window, &title, 130, 0, 300, 70,
                           LABEL_COLOR_WHITE, LABEL_FONT_MICROSOFT_YAHEI_30,
                           text);

  label_pos_t line_pos = create_label_pos(130, 88, 650, 2, LABEL_COLOR_WHITE,
                                          LABEL_FONT_PLAGIATA_27,
                                          VALUE_TYPE_CHAR, (label_value_t){""});
  create_label(menu_window, &line, line_pos);
  lv_obj_set_style_bg_opa(line, LV_OPA_COVER, 0);
  set_screen_color(line, lv_color_make(0xFF, 0x00, 0x00));
}

void preview_set_vehicle_details() {
  label_params_t params_info = ui_helpers_params(
      130, 100, lang_text(TEXT_ID_VEHICLE_INFO), RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window, &elements[0], &elements[1], params_info);
  label_params_t params_tc =
      ui_helpers_params(130, 170, "TC", NULL, lang_text(TEXT_ID_OPEN));
  ui_helpers_component(menu_window, &elements[2], &elements[3], params_tc);
  label_params_t params_ess =
      ui_helpers_params(130, 240, "ESS", NULL, lang_text(TEXT_ID_OPEN));
  ui_helpers_component(menu_window, &elements[4], &elements[5], params_ess);
  label_params_t params_quick = ui_helpers_params(
      130, 310, lang_text(TEXT_ID_QUICK_SHIFT), NULL, lang_text(TEXT_ID_OPEN));
  ui_helpers_component(menu_window, &elements[6], &elements[7], params_quick);
  label_params_t params_up = ui_helpers_params(
      130, 380, lang_text(TEXT_ID_UPSHIFT), NULL, lang_text(TEXT_ID_OPEN));
  ui_helpers_component(menu_window, &elements[8], &elements[9], params_up);
}

void preview_phone() {
  label_params_t params_contacts = ui_helpers_params(
      130, 100, lang_text(TEXT_ID_CONTACTS), RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window, &elements[0], &elements[1],
                       params_contacts);
  label_params_t params_calls = ui_helpers_params(
      130, 170, lang_text(TEXT_ID_RECENT_CALLS), RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window, &elements[2], &elements[3], params_calls);
}

void preview_music() {}

void preview_navigation() {}

void preview_settings() {
  label_params_t params_connection =
      ui_helpers_params(130, 100, lang_text(TEXT_ID_DEVICE_CONNECTION),
                        RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window, &elements[0], &elements[1],
                       params_connection);
  label_params_t params_option_1 = ui_helpers_params(
      130, 160, lang_text(TEXT_ID_OPTIONAL_INFO_1), RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window, &elements[2], &elements[3],
                       params_option_1);
  label_params_t params_option_2 = ui_helpers_params(
      130, 220, lang_text(TEXT_ID_OPTIONAL_INFO_2), RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window, &elements[4], &elements[5],
                       params_option_2);
  label_params_t params_auto =
      ui_helpers_params(130, 280, lang_text(TEXT_ID_AUTO_BRIGHTNESS), NULL,
                        lang_text(TEXT_ID_OPEN));
  ui_helpers_component(menu_window, &elements[6], &elements[7], params_auto);
  label_params_t params_unit = ui_helpers_params(
      130, 340, lang_text(TEXT_ID_UNIT_SETTINGS), RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window, &elements[8], &elements[9], params_unit);
  label_params_t params_time = ui_helpers_params(
      130, 400, lang_text(TEXT_ID_TIME_SETTINGS), RIGHT_ARROW_IMG_PATH, NULL);
  ui_helpers_component(menu_window, &elements[10], &elements[11], params_time);
}
