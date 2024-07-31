#include <stdio.h>
#include <string.h>
#include "lvgl/lvgl.h"
#include "../cell.h"

lv_color_t ToolGetColor(TextColor color);
const lv_font_t* ToolGetFont(TextFont font);
lv_coord_t ToolGetWidth(TextFont);

char* 
ReplaceSubstr(const char* str, const char* old_substr, const char* new_substr);
lv_obj_t* Label(lv_obj_t *bg, lv_obj_t **lv, lable_pos pos);