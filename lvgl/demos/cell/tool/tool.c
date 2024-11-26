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
    {LABEL_FONT_MICROSOFT_YAHEI_30, &MicrosoftYaHei_30},
    {LABEL_FONT_HARMONYOS_16, &HarmonyOS_Sans_SC_16},
    {LABEL_FONT_HARMONYOS_20, &HarmonyOS_Sans_SC_20},
    {LABEL_FONT_HARMONYOS_24, &HarmonyOS_Sans_SC_24},
    {LABEL_FONT_HARMONYOS_28, &HarmonyOS_Sans_SC_28},
    {LABEL_FONT_HARMONYOS_36, &HarmonyOS_Sans_SC_36},
    {LABEL_FONT_HARMONYOS_40, &HarmonyOS_Sans_SC_40},
    {LABEL_FONT_HARMONYOS_80, &HarmonyOS_Sans_SC_80},
    {LABEL_FONT_HARMONYOS_MEDIUM_30, &HarmonyOS_Sans_SC_30}};

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
