#include "tool.h"
#include "../other/motor_model.h"

lv_color_t color_map[kColorCount];

typedef struct {
  Font font;
  const lv_font_t* font_ptr;
} FontMap;

FontMap font_map[kFontCount] = {{kPlagiata_27, &Plagiata_27},
                                {kPlagiata_37, &Plagiata_37},
                                {kSourceHanSansCN_18, &SourceHanSansCN_18},
                                {kSourceHanSansCN_22, &SourceHanSansCN_22},
                                {kSourceHanSansCN_28, &SourceHanSansCN_28},
                                {kSourceHanSansCN_34, &SourceHanSansCN_34},
                                {kMicrosoftYaHei_20, &MicrosoftYaHei_20}};

void ToolInit() { ToolInitColorMap(); }

void ToolInitColorMap() {
  color_map[kColorWhite] = lv_color_make(255, 255, 255);
  color_map[kColorBlack] = lv_color_make(0, 0, 0);
  color_map[kColorRed] = lv_color_make(255, 0, 0);
  color_map[kColorGreen] = lv_color_make(0, 255, 0);
  color_map[kColorBlue] = lv_color_make(0, 0, 255);
  color_map[kColorLimeGreen] = lv_color_make(0x31, 0xC9, 0x18);
}

lv_color_t ToolGetColor(Color color) {
  if (color < 0 || color >= kColorCount) {
    return lv_color_make(0, 0, 0);
  }
  return color_map[color];
}

const lv_font_t* ToolGetFont(Font font) {
  if (font < 0 || font >= kFontCount) {
    return &SourceHanSansCN_18;
  }
  return font_map[font].font_ptr;
}

lv_coord_t ToolGetWidth(Font font) {
  switch (font) {
    case kPlagiata_27:
      return 10;
  }
}

void ReplaceSubstring(char* str, const char* old_substr,
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

lv_obj_t* CreateLabel(lv_obj_t* bg, lv_obj_t** lv, LabelPos pos) {
  lv_obj_t* obj = lv_label_create(bg);
  if (pos.value_type == kTextChar) {
    lv_label_set_text(obj, pos.value.sz);
  } else if (pos.value_type == kTextFloat) {
    char sz[32] = {0};
    sprintf(sz, "%.1f", pos.value.double_value);
    lv_label_set_text(obj, sz);
  } else if (pos.value_type == kTextInt) {
    lv_label_set_text_fmt(obj, "%d", pos.value.int_value);
  }
  lv_obj_set_pos(obj, pos.x, pos.y);
  lv_obj_set_size(obj, pos.width, pos.height);
  lv_obj_set_style_text_font(obj, ToolGetFont(pos.font), 0);
  lv_obj_set_style_text_color(obj, ToolGetColor(pos.color), 0);
  *lv = obj;
  return obj;
}

ImagePos CreateImagePos(const char* image_path, int x, int y) {
  ImagePos pos = {.x = x, .y = y};
  strncpy(pos.image, image_path, sizeof(pos.image) - 1);
  pos.image[sizeof(pos.image) - 1] = '\0';
  return pos;
}

LabelPos CreateLabelPos(int x, int y, int width, int height, Color color,
                        Font font, ValueType type, LabelValue text) {
  LabelPos pos = {.x = x,
                  .y = y,
                  .width = width,
                  .height = height,
                  .color = color,
                  .font = font,
                  .value_type = type};

  switch (type) {
    case kTextChar:
      strncpy(pos.value.sz, text.sz, sizeof(pos.value.sz) - 1);
      pos.value.sz[sizeof(pos.value.sz) - 1] = '\0';
      break;
    case kTextFloat:
      pos.value.double_value = text.double_value;
      break;
    case kTextInt:
      pos.value.int_value = text.int_value;
      break;
    default:
      pos.value.int_value = 0;
      break;
  }

  return pos;
}

lv_color_t ToolGetThemeColor() {
  return MotorModelGetDayNightMode() == kDayMode ? lv_color_black()
                                                 : lv_color_white();
}

void ToolToggleDayNightMode(char* image) {
  if (MotorModelGetDayNightMode() == kDayMode) {
    ReplaceSubstring(image, "night", "day");
  } else {
    ReplaceSubstring(image, "day", "night");
  }
}

void ToolSetTextOnMode(lv_obj_t* obj, int night_color, int day_color) {
  int color =
      (MotorModelGetDayNightMode() == kNightMode) ? night_color : day_color;
  lv_obj_set_style_text_color(obj, ToolGetColor(color), 0);
}

void ToolSetTextOnModeAndUpdate(lv_obj_t* obj, Color* color_prop,
                                int night_color, int day_color) {
  *color_prop =
      (MotorModelGetDayNightMode() == kNightMode) ? night_color : day_color;
  lv_obj_set_style_text_color(obj, ToolGetColor(*color_prop), 0);
}

const char* ToolGetThemeSuffix() {
  return (MotorModelGetDayNightMode() == kDayMode) ? "day" : "night";
}

Color ToolGetColorBase() {
  return (MotorModelGetDayNightMode() == kDayMode) ? kColorBlack : kColorWhite;
}
