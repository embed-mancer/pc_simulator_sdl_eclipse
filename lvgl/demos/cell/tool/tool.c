#include "tool.h"

typedef struct {
  color_t color;
  lv_color_t (*getColorFunc)();
} ColorMap;
lv_color_t colorMap[kColorCount];

typedef struct {
  font_t font;
  const lv_font_t* fontPtr;
} FontMap;
FontMap fontMap[kFontCount] = {{kPlagiata_27, &Plagiata_27},
                               {kPlagiata_37, &Plagiata_37},
                               {kSourceHanSansCN_18, &SourceHanSansCN_18}};

void ToolInit() { ToolInitColorMap(); }

void ToolInitColorMap() {
  colorMap[kColorWhite] = lv_color_make(255, 255, 255);
  colorMap[kColorBlack] = lv_color_make(0, 0, 0);
  colorMap[kColorRed] = lv_color_make(255, 0, 0);
  colorMap[kColorGreen] = lv_color_make(0, 255, 0);
  colorMap[kColorBlue] = lv_color_make(0, 0, 255);
}

lv_color_t ToolGetColor(color_t color) {
  if (color < 0 || color >= kColorCount) {
    return lv_color_make(0, 0, 0);
  }
  return colorMap[color];
}

const lv_font_t* ToolGetFont(font_t font) {
  if (font < 0 || font >= kFontCount) {
    return &SourceHanSansCN_18;
  }
  return fontMap[font].fontPtr;
}

lv_coord_t ToolGetWidth(font_t font) {
  switch (font) {
    case kPlagiata_27:
      return 10;
  }
}

char* ReplaceSubstr(const char* str, const char* old_substr,
                    const char* new_substr) {
  const char* p = str;
  char* result;
  int count = 0;
  int old_len = strlen(old_substr);
  int new_len = strlen(new_substr);

  while ((p = strstr(p, old_substr))) {
    count++;
    p += old_len;
  }

  result = (char*)malloc(strlen(str) + count * (new_len - old_len) + 1);
  if (!result) return NULL;

  p = str;
  char* res_ptr = result;
  while ((p = strstr(p, old_substr))) {
    size_t len = p - str;
    strncpy(res_ptr, str, len);
    res_ptr += len;

    strcpy(res_ptr, new_substr);
    res_ptr += new_len;

    p += old_len;
    str = p;
  }
  strcpy(res_ptr, str);

  return result;
}

lv_obj_t* Label(lv_obj_t* bg, lv_obj_t** lv, label_pos pos) {
  // if (lv)
  //   return lv;
  lv_obj_t* obj = lv_label_create(bg);
  if (pos.value_type == kTextChar)
    lv_label_set_text(obj, pos.value.sz);
  else if (pos.value_type == kTextFloat) {
    char sz[32] = {0};
    sprintf(sz, "%.1f", pos.value.f);
    lv_label_set_text(obj, sz);
  } else if (pos.value_type == kTextInt)
    lv_label_set_text_fmt(obj, "%d", pos.value.i);
  lv_obj_set_pos(obj, pos.x, pos.y);
  lv_obj_set_size(obj, pos.w, pos.h);
  lv_obj_set_style_text_font(obj, ToolGetFont(pos.font), 0);
  lv_obj_set_style_text_color(obj, ToolGetColor(pos.color), 0);
  // lv_obj_set_align(obj, LV_ALIGN_TOP_LEFT);
  // lv_label_set_long_mode(obj, LV_LABEL_LONG_WRAP);
  *lv = obj;
  return obj;
}

image_pos CreateImagePos(const char* image_path, int x, int y) {
  image_pos pos = {.x = x, .y = y};
  strcpy(pos.image, image_path);
  pos.image[sizeof(pos.image) - 1] = '\0';
  return pos;
}

label_pos CreateLabelPos(int x, int y, int w, int h, color_t color, font_t font,
                         value_type_t type, LabelValue text) {
  label_pos pos = {.x = x,
                   .y = y,
                   .w = w,
                   .h = h,
                   .color = color,
                   .font = font,
                   .value_type = type};

  switch (type) {
    case kTextChar:
      strcpy(pos.value.sz, text.sz);
      pos.value.sz[sizeof(pos.value.sz) - 1] = '\0';
      break;
    case kTextFloat:
      pos.value.f = text.f;
      break;
    case kTextInt:
      pos.value.i = text.i;
      break;
    default:
      pos.value.i = 0;
      break;
  }

  return pos;
}
