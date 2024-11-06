#include <stdio.h>
#include <string.h>

#include "../cell.h"
#include "lvgl/lvgl.h"

void tool_init();
void tool_init_color_map();
lv_color_t tool_get_color(label_color_t color);
const lv_font_t* tool_get_font(label_font_t font);
lv_coord_t tool_get_width(label_font_t);

void replace_substring(char* str, const char* old_substr,
                       const char* new_substr);
lv_obj_t* create_label(lv_obj_t* bg, lv_obj_t** lv, label_pos_t pos);
image_pos_t create_image_pos(const char* image_path, int x, int y);
label_pos_t create_label_pos(int x, int y, int w, int h, label_color_t color,
                             label_font_t font, value_type_t type,
                             label_value_t text);
lv_color_t ToolGetThemeColor();
void tool_toggle_day_night_mode(char* image);
void tool_set_text_on_mode(lv_obj_t* obj, int night_color, int day_color);
void tool_set_text_on_mode_and_update(lv_obj_t* obj, label_color_t* color_prop,
                                      int night_color, int day_color);

const char* tool_get_theme_suffix();
label_color_t tool_get_color_base();