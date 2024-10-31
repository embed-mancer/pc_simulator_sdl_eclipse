#include <stdio.h>
#include <string.h>

#include "../cell.h"
#include "lvgl/lvgl.h"

void ToolInit();
void ToolInitColorMap();
lv_color_t ToolGetColor(Color color);
const lv_font_t* ToolGetFont(Font font);
lv_coord_t ToolGetWidth(Font);

void ReplaceSubstring(char* str, const char* old_substr, const char* new_substr);
lv_obj_t* CreateLabel(lv_obj_t* bg, lv_obj_t** lv, LabelPos pos);
ImagePos CreateImagePos(const char* image_path, int x, int y);
LabelPos CreateLabelPos(int x, int y, int w, int h, Color color, Font font,
                         ValueType type, LabelValue text);
lv_color_t ToolGetThemeColor();
void ToolToggleDayNightMode(char* image);
void ToolSetTextOnMode(lv_obj_t* obj, int night_color, int day_color);
void ToolSetTextOnModeAndUpdate(lv_obj_t* obj, Color* color_prop,
                                int night_color, int day_color);

const char* ToolGetThemeSuffix();
