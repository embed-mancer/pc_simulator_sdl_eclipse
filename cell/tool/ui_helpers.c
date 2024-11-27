#include "../menu/menu_navigate.h"
#include "../tool/tool.h"
#include "lvgl/lvgl.h"

#define INIT_DEFAULT_LABEL_PARAMS()                                          \
  (label_params_t) {                                                         \
    .label_x = 130, .label_y = 50, .label_width = 150, .label_height = 60,   \
    .secondary_label_x = 616, .image_x = 742,                                \
    .label_color = LABEL_COLOR_WHITE, .label_font = LABEL_FONT_HARMONYOS_24, \
    .label_text = "", .secondary_label_text = NULL, .image_path = NULL       \
  }

#define INIT_SETTINGS_LABEL_PARAMS()                                         \
  (label_params_t) {                                                         \
    .label_x = 250, .label_y = 50, .label_width = 150, .label_height = 70,   \
    .secondary_label_x = 616, .image_x = 750,                                \
    .label_color = LABEL_COLOR_WHITE, .label_font = LABEL_FONT_HARMONYOS_24, \
    .label_text = "", .secondary_label_text = NULL, .image_path = NULL       \
  }

label_params_t ui_helpers_params(int label_x, int label_y,
                                 const char* label_text, const char* image_path,
                                 const char* secondary_label_text) {
  label_params_t params = INIT_DEFAULT_LABEL_PARAMS();
  params.label_x = label_x;
  params.label_y = label_y;
  params.label_text = label_text;
  params.label_color = tool_get_color_base();
  params.image_path = image_path;
  params.secondary_label_text = secondary_label_text;
  return params;
}

label_params_t ui_helpers_settings_params(int label_x, int label_y,
                                          const char* label_text,
                                          const char* image_path,
                                          const char* secondary_label_text) {
  label_params_t params = INIT_SETTINGS_LABEL_PARAMS();
  params.label_x = label_x;
  params.label_y = label_y;
  params.label_text = label_text;
  params.label_color = tool_get_color_base();
  params.image_path = image_path;
  params.secondary_label_text = secondary_label_text;
  return params;
}

void ui_helpers_component(lv_obj_t* parent, lv_obj_t** primary_obj,
                          lv_obj_t** second_obj, label_params_t params) {
  ui_helpers_create_label_left(parent, primary_obj, params.label_x,
                               params.label_y, params.label_width,
                               params.label_height, params.label_color,
                               params.label_font, params.label_text);
  if (params.image_path != NULL) {
    image_pos_t image_position = ui_helpers_init_image_position(
        params.image_path, params.image_x,
        params.label_y + params.label_height / 2 - 4);
    ui_helpers_create_image(menu_window_get(), second_obj, image_position);
  }

  if (params.secondary_label_text != NULL) {
    ui_helpers_create_label_right(
        parent, second_obj, params.secondary_label_x, params.label_y,
        params.label_width, params.label_height, params.label_color,
        params.label_font, params.secondary_label_text);
  }
}

void ui_helpers_menu_image(lv_obj_t** elements, const char* suffix,
                           int element_index, int x, int y) {
  char image_path[MAX_IMAGE_CHARS];
  sprintf(image_path, RES_PRFIX "menu/%s/%s", tool_get_theme_suffix(), suffix);
  image_pos_t pos = ui_helpers_init_image_position(image_path, x, y);
  ui_helpers_create_image(menu_window_get(), &elements[element_index], pos);
}

void ui_helpers_create_image(lv_obj_t* bg, lv_obj_t** lv, image_pos_t pos) {
  if (*lv == NULL) {
    *lv = lv_img_create(bg);
  }
  lv_obj_set_pos(*lv, pos.x, pos.y);
  lv_img_set_src(*lv, pos.image);
}

void ui_helpers_create_label(lv_obj_t* bg, lv_obj_t** lv, label_pos_t pos) {
  if (*lv)
    return;
  *lv = lv_label_create(bg);
  if (!*lv)
    return;
  if (pos.value_type_e == VALUE_TYPE_CHAR) {
    lv_label_set_text(*lv, pos.value.sz);
  } else if (pos.value_type_e == VALUE_TYPE_FLOAT) {
    char sz[32] = {0};
    sprintf(sz, "%.1f", pos.value.double_value);
    lv_label_set_text(*lv, sz);
  } else if (pos.value_type_e == VALUE_TYPE_INT) {
    lv_label_set_text_fmt(*lv, "%d", pos.value.int_value);
  }
  lv_obj_set_pos(*lv, pos.x, pos.y);
  lv_obj_set_size(*lv, pos.width, pos.height);
  lv_obj_set_style_text_font(*lv, tool_get_font(pos.font), 0);
  lv_obj_set_style_text_color(*lv, tool_get_color(pos.color), 0);
}

void create_label_with_alignment(lv_obj_t* parent, lv_obj_t** label, int x,
                                 int y, int width, int height,
                                 label_color_e color, label_font_e font,
                                 const char* text, lv_text_align_t align) {
  label_pos_t label_pos = ui_helpers_init_label_position(
      x, y, width, height, color, font, VALUE_TYPE_CHAR,
      ui_helpers_init_label_value(text));

  ui_helpers_create_label(parent, label, label_pos);
  lv_obj_set_style_text_align(*label, align, 0);

  int line_height = lv_font_get_line_height(tool_get_font(font));
  lv_obj_set_y(*label, (height - line_height) / 2 + y);
}

void ui_helpers_create_label_left(lv_obj_t* parent, lv_obj_t** label, int x,
                                  int y, int width, int height,
                                  label_color_e color, label_font_e font,
                                  const char* text) {
  create_label_with_alignment(parent, label, x, y, width, height, color, font,
                              text, LV_TEXT_ALIGN_LEFT);
}

void ui_helpers_create_label_right(lv_obj_t* parent, lv_obj_t** label, int x,
                                   int y, int width, int height,
                                   label_color_e color, label_font_e font,
                                   const char* text) {
  create_label_with_alignment(parent, label, x, y, width, height, color, font,
                              text, LV_TEXT_ALIGN_RIGHT);
}

void ui_helpers_create_label_center(lv_obj_t* parent, lv_obj_t** label, int x,
                                    int y, int width, int height,
                                    label_color_e color, label_font_e font,
                                    const char* text) {
  create_label_with_alignment(parent, label, x, y, width, height, color, font,
                              text, LV_TEXT_ALIGN_CENTER);
}

image_pos_t ui_helpers_init_image_position(const char* image_path, int x,
                                           int y) {
  image_pos_t pos = {.x = x, .y = y};
  strncpy(pos.image, image_path, sizeof(pos.image) - 1);
  pos.image[sizeof(pos.image) - 1] = '\0';
  return pos;
}

label_value_t ui_helpers_init_label_value(const char* str) {
  label_value_t value = {0};
  snprintf(value.sz, sizeof(value.sz), "%s", str);
  return value;
}

label_pos_t ui_helpers_init_label_position(int x, int y, int width, int height,
                                           label_color_e color,
                                           label_font_e font, value_type_e type,
                                           label_value_t text) {
  label_pos_t pos = {.x = x,
                     .y = y,
                     .width = width,
                     .height = height,
                     .color = color,
                     .font = font,
                     .value_type_e = type};

  switch (type) {
    case VALUE_TYPE_CHAR:
      strncpy(pos.value.sz, text.sz, sizeof(pos.value.sz) - 1);
      pos.value.sz[sizeof(pos.value.sz) - 1] = '\0';
      break;
    case VALUE_TYPE_FLOAT:
      pos.value.double_value = text.double_value;
      break;
    case VALUE_TYPE_INT:
      pos.value.int_value = text.int_value;
      break;
    default:
      pos.value.int_value = 0;
      break;
  }

  return pos;
}

void initialize_background(lv_obj_t** bg, lv_obj_t* parent, int x, int y,
                           int width, int height, lv_color_t color) {
  *bg = lv_label_create(parent);
  lv_obj_set_pos(*bg, x, y);
  lv_obj_set_size(*bg, width, height);
  lv_label_set_text(*bg, "");
  lv_obj_set_style_bg_opa(*bg, LV_OPA_COVER, 0);
  lv_obj_set_style_bg_color(*bg, color, 0);
}

void ui_helpers_centered_y_positions(int* y_positions, int count,
                                     int item_height) {
  int start_y = 240 - (item_height * count) / 2;
  for (int i = 0; i < count; ++i) {
    y_positions[i] = start_y + i * item_height;
  }
}

void ui_helpers_set_element_style(lv_obj_t* element, bool selected,
                                  lv_color_t color) {
  const lv_font_t* font =
      selected ? &HarmonyOS_Sans_SC_36 : &HarmonyOS_Sans_SC_24;
  lv_obj_set_style_text_font(element, font, 0);
  lv_obj_set_style_text_color(element, color, 0);
}

int ui_helpers_cache_images(const char* img_paths[], int img_count,
                            const char* single_img_path) {
  if (single_img_path != NULL) {
    _lv_img_cache_open(single_img_path, lv_color_black(), 0);
  } else if (img_paths != NULL) {
    for (int i = 0; i < img_count; i++) {
      _lv_img_cache_open(img_paths[i], lv_color_black(), 0);
    }
  } else {
    return -1;
  }

  return 0;
}
