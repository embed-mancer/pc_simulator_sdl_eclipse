#include "tool.h"
#include "../other/motor_model.h"

lv_color_t color_map[LABEL_COLOR_COUNT];

typedef struct {
  label_font_e font;
  const lv_font_t* font_ptr;
} font_map_t;

font_map_t font_map[LABEL_FONT_COUNT] = {
    {LABEL_FONT_PLAGIATA_27, &Plagiata_27},
    {LABEL_FONT_PLAGIATA_37, &Plagiata_37},
    {LABEL_FONT_SOURCEHANSANSCN_18, &SourceHanSansCN_18},
    {LABEL_FONT_SOURCEHANSANSCN_22, &SourceHanSansCN_22},
    {LABEL_FONT_SOURCEHANSANSCN_28, &SourceHanSansCN_28},
    {LABEL_FONT_SOURCEHANSANSCN_34, &SourceHanSansCN_34},
    {LABEL_FONT_MICROSOFT_YAHEI_18, &MicrosoftYaHei_18},
    {LABEL_FONT_MICROSOFT_YAHEI_20, &MicrosoftYaHei_20},
    {LABEL_FONT_MICROSOFT_YAHEI_22, &MicrosoftYaHei_22},
    {LABEL_FONT_MICROSOFT_YAHEI_30, &MicrosoftYaHei_30}};

void tool_init() {
  tool_init_color_map();
}

void tool_init_color_map() {
  color_map[LABEL_COLOR_WHITE]      = lv_color_make(255, 255, 255);
  color_map[LABEL_COLOR_BLACK]      = lv_color_make(0, 0, 0);
  color_map[LABEL_COLOR_RED]        = lv_color_make(255, 0, 0);
  color_map[LABEL_COLOR_GREEN]      = lv_color_make(0, 255, 0);
  color_map[LABEL_COLOR_BLUE]       = lv_color_make(0, 0, 255);
  color_map[LABEL_COLOR_LIME_GREEN] = lv_color_make(0x31, 0xC9, 0x18);
}

lv_color_t tool_get_color(label_color_e color) {
  if (color < 0 || color >= LABEL_COLOR_COUNT) {
    return lv_color_make(0, 0, 0);
  }
  return color_map[color];
}

const lv_font_t* tool_get_font(label_font_e font) {
  if (font < 0 || font >= LABEL_FONT_COUNT) {
    return &SourceHanSansCN_18;
  }
  return font_map[font].font_ptr;
}

lv_coord_t tool_get_width(label_font_e font) {
  switch (font) {
  case LABEL_FONT_PLAGIATA_27:
    return 10;
  default:
    return 0;
  }
}

void replace_substring(char* str, const char* old_substr,
                       const char* new_substr) {
  char* pos;
  int old_len = strlen(old_substr);
  int new_len = strlen(new_substr);

  while ((pos = strstr(str, old_substr)) != NULL) {
    if (new_len != old_len) {
      memmove(pos + new_len, pos + old_len, strlen(pos + old_len) + 1);
    }
    strncpy(pos, new_substr, new_len);
  }
}

void create_img(lv_obj_t* bg, lv_obj_t** lv, image_pos_t pos) {
  if (*lv)
    return;
  *lv = lv_img_create(bg);
  lv_obj_set_pos(*lv, pos.x, pos.y);
  lv_img_set_src(*lv, pos.image);
}

void create_label(lv_obj_t* bg, lv_obj_t** lv, label_pos_t pos) {
  if (*lv)
    return;
  *lv = lv_label_create(bg);
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

void create_center_left_label(lv_obj_t* parent, lv_obj_t** label, int x, int y,
                              int width, int height, label_color_e color,
                              label_font_e font, const char* text) {
  label_pos_t label_pos =
      create_label_pos(x, y, width, height, color, font, VALUE_TYPE_CHAR,
                       create_label_value(text));

  create_label(parent, label, label_pos);

  int line_height = lv_font_get_line_height(tool_get_font(font));

  lv_obj_set_style_text_align(*label, LV_TEXT_ALIGN_LEFT, 0);
  lv_obj_set_y(*label, (height - line_height) / 2 + y);
}

void create_center_right_label(lv_obj_t* parent, lv_obj_t** label, int x, int y,
                               int width, int height, label_color_e color,
                               label_font_e font, const char* text) {
  label_pos_t label_pos =
      create_label_pos(x, y, width, height, color, font, VALUE_TYPE_CHAR,
                       create_label_value(text));

  create_label(parent, label, label_pos);

  int line_height = lv_font_get_line_height(tool_get_font(font));

  lv_obj_set_style_text_align(*label, LV_TEXT_ALIGN_RIGHT, 0);
  lv_obj_set_y(*label, (height - line_height) / 2 + y);
}

image_pos_t create_image_pos(const char* image_path, int x, int y) {
  image_pos_t pos = {.x = x, .y = y};
  strncpy(pos.image, image_path, sizeof(pos.image) - 1);
  pos.image[sizeof(pos.image) - 1] = '\0';
  return pos;
}

label_value_t create_label_value(const char* str) {
  label_value_t value = {0};
  snprintf(value.sz, sizeof(value.sz), "%s", str);
  return value;
}

label_pos_t create_label_pos(int x, int y, int width, int height,
                             label_color_e color, label_font_e font,
                             value_type_e type, label_value_t text) {
  label_pos_t pos = {.x            = x,
                     .y            = y,
                     .width        = width,
                     .height       = height,
                     .color        = color,
                     .font         = font,
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

lv_color_t tool_get_theme_color() {
  return motor_model_get_day_night_mode() == METER_MODE_DAY ? lv_color_black()
                                                            : lv_color_white();
}

void tool_toggle_day_night(char* image) {
  if (motor_model_get_day_night_mode() == METER_MODE_DAY) {
    replace_substring(image, "night", "day");
  } else {
    replace_substring(image, "day", "night");
  }
}

void tool_set_text_on_mode(lv_obj_t* obj, int night_color, int day_color) {
  int color = (motor_model_get_day_night_mode() == METER_MODE_NIGHT)
                  ? night_color
                  : day_color;
  lv_obj_set_style_text_color(obj, tool_get_color(color), 0);
}

void tool_set_text_on_mode_and_update(lv_obj_t* obj, label_color_e* color_prop,
                                      int night_color, int day_color) {
  *color_prop = (motor_model_get_day_night_mode() == METER_MODE_NIGHT)
                    ? night_color
                    : day_color;
  lv_obj_set_style_text_color(obj, tool_get_color(*color_prop), 0);
}

const char* tool_get_theme_suffix() {
  return (motor_model_get_day_night_mode() == METER_MODE_DAY) ? "day" : "night";
}

label_color_e tool_get_color_base() {
  return (motor_model_get_day_night_mode() == METER_MODE_DAY)
             ? LABEL_COLOR_BLACK
             : LABEL_COLOR_WHITE;
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
