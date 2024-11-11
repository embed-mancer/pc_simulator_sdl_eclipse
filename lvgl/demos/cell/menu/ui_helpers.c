#include "ui_helpers.h"

extern lv_obj_t *menu_window;

#define INIT_DEFAULT_LABEL_PARAMS()                                        \
  (label_params_t) {                                                       \
    .label_x = 130, .label_y = 50, .label_width = 150, .label_height = 70, \
    .secondary_label_x = 616, .image_x = 750,                              \
    .label_color = LABEL_COLOR_WHITE,                                      \
    .label_font = LABEL_FONT_MICROSOFT_YAHEI_22, .label_text = "",         \
    .secondary_label_text = NULL, .image_path = NULL                       \
  }

#define INIT_SETTINGS_LABEL_PARAMS()                                       \
  (label_params_t) {                                                       \
    .label_x = 250, .label_y = 50, .label_width = 150, .label_height = 70, \
    .secondary_label_x = 616, .image_x = 750,                              \
    .label_color = LABEL_COLOR_WHITE,                                      \
    .label_font = LABEL_FONT_MICROSOFT_YAHEI_20, .label_text = "",         \
    .secondary_label_text = NULL, .image_path = NULL                       \
  }

label_params_t ui_helpers_params(int label_x, int label_y,
                                 const char *label_text, const char *image_path,
                                 const char *secondary_label_text) {
  label_params_t params = INIT_DEFAULT_LABEL_PARAMS();
  params.label_x = label_x;
  params.label_y = label_y;
  params.label_text = label_text;
  params.image_path = image_path;
  params.secondary_label_text = secondary_label_text;
  return params;
}

label_params_t ui_helpers_settings_params(int label_x, int label_y,
                                          const char *label_text,
                                          const char *image_path,
                                          const char *secondary_label_text) {
  label_params_t params = INIT_SETTINGS_LABEL_PARAMS();
  params.label_x = label_x;
  params.label_y = label_y;
  params.label_text = label_text;
  params.image_path = image_path;
  params.secondary_label_text = secondary_label_text;
  return params;
}

void ui_helpers_component(lv_obj_t *parent, lv_obj_t **primary_obj,
                          lv_obj_t **second_obj, label_params_t params) {
  create_center_left_label(parent, primary_obj, params.label_x, params.label_y,
                           params.label_width, params.label_height,
                           params.label_color, params.label_font,
                           params.label_text);
  if (params.image_path != NULL) {
    image_pos_t image_position = create_image_pos(
        params.image_path, params.image_x, params.label_y + 27);
    create_img(menu_window, second_obj, image_position);
  }

  if (params.secondary_label_text != NULL) {
    create_center_right_label(parent, second_obj, params.secondary_label_x,
                              params.label_y, params.label_width,
                              params.label_height, params.label_color,
                              params.label_font, params.secondary_label_text);
  }
}
