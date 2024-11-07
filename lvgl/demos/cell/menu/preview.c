#include "preview.h"
#include "../cell.h"

extern lv_obj_t *menu_window;
static lv_obj_t *title = NULL;
static lv_obj_t *line = NULL;

#define ELEMENTS_COUNT 12
#define RIGHT_ARROW_IMG_PATH (RES_PRFIX "menu/right_arrow.png")

#define LABEL_X_POSITION 130
#define LABEL_WIDTH 150
#define LABEL_HEIGHT 70
#define IMAGE_X_POSITION 650
#define IMAGE_Y_OFFSET 27
#define TITLE_WIDTH 200
#define TITLE_HEIGHT 90
#define LINE_START_Y 88
#define LINE_WIDTH 650
#define LINE_HEIGHT 2

#define FONT_SIZE_LABEL LABEL_FONT_MICROSOFT_YAHEI_22
#define FONT_SIZE_TITLE LABEL_FONT_MICROSOFT_YAHEI_30
#define LABEL_COLOR LABEL_COLOR_WHITE
#define LINE_COLOR LABEL_COLOR_GREEN

typedef void (*page_handler_t)(void);
static lv_obj_t *elements[ELEMENTS_COUNT] = {NULL};

static void handle_default_page() {}
static const page_handler_t page_handlers[] = {
    preview_set_vehicle_details, preview_phone, preview_music,
    preview_navigation, preview_settings};

// 优化后的函数实现
static void create_label_with_image(int label_y, lv_obj_t *parent,
                                    lv_obj_t **label_obj, lv_obj_t **image_obj,
                                    const char *label_text,
                                    const char *image_path) {
  create_center_left_label(parent, label_obj, LABEL_X_POSITION, label_y,
                           LABEL_WIDTH, LABEL_HEIGHT, LABEL_COLOR,
                           FONT_SIZE_LABEL, label_text);

  image_pos_t image_position =
      create_image_pos(image_path, IMAGE_X_POSITION, label_y + IMAGE_Y_OFFSET);
  create_img(parent, image_obj, image_position);
}

static void create_label_with_label(int left_label_y, lv_obj_t *parent,
                                    lv_obj_t **left_label_obj,
                                    lv_obj_t **right_label_obj,
                                    const char *left_text,
                                    const char *right_text) {
  create_center_left_label(parent, left_label_obj, LABEL_X_POSITION,
                           left_label_y, LABEL_WIDTH, LABEL_HEIGHT, LABEL_COLOR,
                           FONT_SIZE_LABEL, left_text);
  create_center_right_label(parent, right_label_obj, IMAGE_X_POSITION - 84,
                            left_label_y, 100, LABEL_HEIGHT, LABEL_COLOR,
                            FONT_SIZE_LABEL, right_text);
}

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

  create_center_left_label(menu_window, &title, LABEL_X_POSITION, 0,
                           TITLE_WIDTH, TITLE_HEIGHT, LABEL_COLOR,
                           FONT_SIZE_TITLE, text);

  label_pos_t line_pos = create_label_pos(
      LABEL_X_POSITION, LINE_START_Y, LINE_WIDTH, LINE_HEIGHT, LINE_COLOR,
      LABEL_FONT_PLAGIATA_27, VALUE_TYPE_CHAR, (label_value_t){""});
  create_label(menu_window, &line, line_pos);
  lv_obj_set_style_bg_opa(line, LV_OPA_COVER, 0);
  set_screen_color(line, lv_color_make(0xFF, 0x00, 0x00));
}

void preview_set_vehicle_details() {
  create_label_with_image(100, menu_window, &elements[0], &elements[1],
                          lang_text(TEXT_ID_VEHICLE_INFO),
                          RIGHT_ARROW_IMG_PATH);
  create_label_with_label(170, menu_window, &elements[2], &elements[3], "TC",
                          lang_text(TEXT_ID_CLOSE));
  create_label_with_label(240, menu_window, &elements[4], &elements[5], "ESS",
                          lang_text(TEXT_ID_CLOSE));
  create_label_with_label(310, menu_window, &elements[6], &elements[7],
                          lang_text(TEXT_ID_QUICK_SHIFT),
                          lang_text(TEXT_ID_CLOSE));
  create_label_with_label(380, menu_window, &elements[8], &elements[9],
                          lang_text(TEXT_ID_UPSHIFT), lang_text(TEXT_ID_CLOSE));
}

void preview_phone() {
  create_label_with_image(100, menu_window, &elements[0], &elements[1],
                          lang_text(TEXT_ID_CONTACTS), RIGHT_ARROW_IMG_PATH);
  create_label_with_image(170, menu_window, &elements[2], &elements[3],
                          lang_text(TEXT_ID_RECENT_CALLS),
                          RIGHT_ARROW_IMG_PATH);
}

void preview_music() {}

void preview_navigation() {}

void preview_settings() {
  create_label_with_image(100, menu_window, &elements[0], &elements[1],
                          lang_text(TEXT_ID_DEVICE_CONNECTION),
                          RIGHT_ARROW_IMG_PATH);
  create_label_with_image(160, menu_window, &elements[2], &elements[3],
                          lang_text(TEXT_ID_OPTIONAL_INFO_1),
                          RIGHT_ARROW_IMG_PATH);
  create_label_with_image(220, menu_window, &elements[4], &elements[5],
                          lang_text(TEXT_ID_OPTIONAL_INFO_2),
                          RIGHT_ARROW_IMG_PATH);
  create_label_with_label(280, menu_window, &elements[6], &elements[7],
                          lang_text(TEXT_ID_AUTO_BRIGHTNESS),
                          lang_text(TEXT_ID_OPEN));
  create_label_with_image(340, menu_window, &elements[8], &elements[9],
                          lang_text(TEXT_ID_UNIT_SETTINGS),
                          RIGHT_ARROW_IMG_PATH);
  create_label_with_image(400, menu_window, &elements[10], &elements[11],
                          lang_text(TEXT_ID_TIME_SETTINGS),
                          RIGHT_ARROW_IMG_PATH);
}
