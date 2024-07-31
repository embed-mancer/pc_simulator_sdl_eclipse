#include "tool.h"

lv_color_t ToolGetColor(TextColor color) {
  switch (color) {
    case kColorWhite:
      return lv_color_white();
    case kColorBlack:
      return lv_color_black();
  }
}

const lv_font_t* ToolGetFont(TextFont font) {
  switch (font) {
    case kPlagiata_27:
      return &Plagiata_27;
    case kPlagiata_37:
      return &Plagiata_37;
  }
}

lv_coord_t ToolGetWidth(TextFont font) {
  switch(font) {
    case kPlagiata_27:
      return 10;
  }
}

char* 
ReplaceSubstr(const char* str, const char* old_substr, const char* new_substr) {
  const char* p = str;
  char* result;
  int count = 0;
  int old_len = strlen(old_substr);
  int new_len = strlen(new_substr);

  // Count the number of occurrences of old_substr
  while ((p = strstr(p, old_substr))) {
      count++;
      p += old_len;
  }

  // Allocate memory for the new string
  result = (char*)malloc(strlen(str) + count * (new_len - old_len) + 1);
  if (!result) return NULL;

  p = str;
  char* res_ptr = result;
  while ((p = strstr(p, old_substr))) {
      // Copy up to the old_substr
      size_t len = p - str;
      strncpy(res_ptr, str, len);
      res_ptr += len;

      // Copy new_substr
      strcpy(res_ptr, new_substr);
      res_ptr += new_len;

      // Advance the pointer
      p += old_len;
      str = p;
  }
  // Copy the rest of the string
  strcpy(res_ptr, str);

  return result;
}

lv_obj_t* Label(lv_obj_t *bg, lv_obj_t **lv, lable_pos pos) {
  // if (lv)
  //   return lv;
  lv_obj_t *obj  = lv_label_create(bg);
  if (pos.value_type == 0)
    lv_label_set_text(obj, pos.text.sz);
  else if (pos.value_type == 1) {
    char sz[32] = {0};
    sprintf(sz, "%.1f", pos.text.f);
    lv_label_set_text(obj, sz);
  }
    // lv_label_set_text(obj, "1.1");
  else if (pos.value_type == 2)
    lv_label_set_text_fmt(obj, "%d", pos.text.i);
  lv_obj_set_pos(obj, pos.x, pos.y);
  lv_obj_set_size(obj, pos.w, pos.h);
  lv_obj_set_style_text_font(obj, ToolGetFont(pos.font), 0);
  lv_obj_set_style_text_color(obj, ToolGetColor(pos.color), 0);
  // lv_obj_set_align(obj, LV_ALIGN_TOP_LEFT);
  // lv_label_set_long_mode(obj, LV_LABEL_LONG_WRAP);
  *lv = obj;
  return obj;
}