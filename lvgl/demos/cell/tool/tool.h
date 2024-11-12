#include <stdio.h>
#include <string.h>

#include "../cell.h"
#include "lvgl/lvgl.h"

void tool_init();
void tool_init_color_map();
lv_color_t tool_get_color(label_color_e color);
const lv_font_t* tool_get_font(label_font_e font);
lv_coord_t tool_get_width(label_font_e);

void replace_substring(char* str, const char* old_substr,
                       const char* new_substr);
void create_img(lv_obj_t* bg, lv_obj_t** lv, image_pos_t pos);
void create_label(lv_obj_t* bg, lv_obj_t** lv, label_pos_t pos);
void create_center_left_label(lv_obj_t* parent, lv_obj_t** label, int x, int y,
                              int width, int height, label_color_e color,
                              label_font_e font, const char* text);
void create_center_right_label(lv_obj_t* parent, lv_obj_t** label, int x, int y,
                              int width, int height, label_color_e color,
                              label_font_e font, const char* text);
image_pos_t create_image_pos(const char* image_path, int x, int y);
label_value_t create_label_value(const char* str);
label_pos_t create_label_pos(int x, int y, int w, int h, label_color_e color,
                             label_font_e font, value_type_e type,
                             label_value_t text);
lv_color_t ToolGetThemeColor();
void tool_toggle_day_night(char* image);
void tool_set_text_on_mode(lv_obj_t* obj, int night_color, int day_color);
void tool_set_text_on_mode_and_update(lv_obj_t* obj, label_color_e* color_prop,
                                      int night_color, int day_color);

const char* tool_get_theme_suffix();
label_color_e tool_get_color_base();
void initialize_background(lv_obj_t** bg, lv_obj_t* parent, int x, int y,
                           int width, int height, lv_color_t);
