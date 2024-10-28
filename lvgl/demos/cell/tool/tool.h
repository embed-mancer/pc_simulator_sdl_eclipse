#include <stdio.h>
#include <string.h>
#include "lvgl/lvgl.h"
#include "../cell.h"

void ToolInit();
void ToolInitColorMap();
lv_color_t ToolGetColor(color_t color);
const lv_font_t* ToolGetFont(font_t font);
lv_coord_t ToolGetWidth(font_t);

char* ReplaceSubstr(const char* str, const char* old_substr,
                    const char* new_substr);
lv_obj_t* Label(lv_obj_t* bg, lv_obj_t** lv, label_pos pos);
image_pos CreateImagePos(const char* image_path, int x, int y);
label_pos CreateLabelPos(int x, int y, int w, int h, color_t color, font_t font,
                         value_type_t type, LabelValue text);
