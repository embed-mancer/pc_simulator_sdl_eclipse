#include <stdio.h>
#include <string.h>
#include "lvgl/lvgl.h"
#include "../cell.h"

lv_color_t ToolGetColor(TextColor color);
const lv_font_t* ToolGetFont(TextFont font);
lv_coord_t ToolGetWidth(TextFont);

void ReplaceSubstr(char *str, char *oldStr, char *newStr);
lv_obj_t* Label(lv_obj_t *bg, lv_obj_t **lv, lable_pos pos);