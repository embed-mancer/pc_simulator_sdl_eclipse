#include "other_view.h"

#include "../other/motor_model.h"

void other_view_init(other_view_t *view) {
  view->trip_key = NULL;
  view->trip_value = NULL;
  view->trip_unit = NULL;
  view->avg_key = NULL;
  view->avg_value = NULL;
  view->avg_unit = NULL;
  view->ride_time_key = NULL;
  view->ride_time_value = NULL;
  view->ride_time_unit = NULL;
  view->battery_key = NULL;
  view->battery_value = NULL;
  view->battery_unit = NULL;
  view->line_split = NULL;
  other_view_create(view);
  other_view_update(view);
}

void other_view_create(other_view_t *view) {
  label_color_t color = tool_get_color_base();
  view->line_split_position =
      create_image_pos(RES_PRFIX "home/night/line_split.png", 33, 263);
  view->trip_key_position =
      create_label_pos(31, 234, 100, 25, color, LABEL_FONT_MICROSOFT_YAHEI_20,
                       VALUE_TYPE_CHAR, (label_value_t){"小计里程"});
  view->trip_value_position =
      create_label_pos(142, 235, 100, 25, color, LABEL_FONT_MICROSOFT_YAHEI_20,
                       VALUE_TYPE_INT, (label_value_t)9999);
  view->trip_unit_position =
      create_label_pos(180, 235, 100, 25, color, LABEL_FONT_MICROSOFT_YAHEI_20,
                       VALUE_TYPE_CHAR, (label_value_t){"km"});
  view->avg_key_position =
      create_label_pos(31, 273, 100, 25, color, LABEL_FONT_MICROSOFT_YAHEI_20,
                       VALUE_TYPE_CHAR, (label_value_t){"平均车速"});
  view->avg_value_position =
      create_label_pos(142, 272, 100, 25, color, LABEL_FONT_MICROSOFT_YAHEI_20,
                       VALUE_TYPE_INT, (label_value_t)58);
  view->avg_unit_position =
      create_label_pos(180, 272, 100, 25, color, LABEL_FONT_MICROSOFT_YAHEI_20,
                       VALUE_TYPE_CHAR, (label_value_t){"km"});
  view->ride_time_key_position =
      create_label_pos(31, 312, 100, 25, color, LABEL_FONT_MICROSOFT_YAHEI_20,
                       VALUE_TYPE_CHAR, (label_value_t){"骑行时间"});
  view->ride_time_value_position =
      create_label_pos(142, 311, 100, 25, color, LABEL_FONT_MICROSOFT_YAHEI_20,
                       VALUE_TYPE_CHAR, (label_value_t){"00:15"});
  view->ride_time_unit_position =
      create_label_pos(180, 311, 100, 25, color, LABEL_FONT_MICROSOFT_YAHEI_20,
                       VALUE_TYPE_CHAR, (label_value_t){"h"});
  view->battery_key_position =
      create_label_pos(31, 352, 100, 25, color, LABEL_FONT_MICROSOFT_YAHEI_20,
                       VALUE_TYPE_CHAR, (label_value_t){"电池电压"});
  view->battery_value_position =
      create_label_pos(142, 351, 100, 25, color, LABEL_FONT_MICROSOFT_YAHEI_20,
                       VALUE_TYPE_FLOAT, (label_value_t)12.0);
  view->battery_unit_position =
      create_label_pos(180, 351, 100, 25, color, LABEL_FONT_MICROSOFT_YAHEI_20,
                       VALUE_TYPE_CHAR, (label_value_t){"V"});
  create_img(view->background, &view->line_split,
                 view->line_split_position);
  create_label(view->background, &view->trip_key, view->trip_key_position);
  create_label(view->background, &view->trip_value, view->trip_value_position);
  create_label(view->background, &view->trip_unit, view->trip_unit_position);
  create_label(view->background, &view->avg_key, view->avg_key_position);
  create_label(view->background, &view->avg_value, view->avg_value_position);
  create_label(view->background, &view->avg_unit, view->avg_unit_position);
  create_label(view->background, &view->ride_time_key,
               view->ride_time_key_position);
  create_label(view->background, &view->ride_time_value,
               view->ride_time_value_position);
  create_label(view->background, &view->ride_time_unit,
               view->ride_time_unit_position);
  create_label(view->background, &view->battery_key,
               view->battery_key_position);
  create_label(view->background, &view->battery_value,
               view->battery_value_position);
  create_label(view->background, &view->battery_unit,
               view->battery_unit_position);
}

void other_view_update(other_view_t *view) {
  other_view_change_pos(view->trip_value, view->trip_unit,
                        view->trip_value_position);
  other_view_change_pos(view->avg_value, view->avg_unit,
                        view->avg_value_position);
  other_view_change_pos(view->ride_time_value, view->ride_time_unit,
                        view->ride_time_value_position);
  other_view_change_pos(view->battery_value, view->battery_unit,
                        view->battery_value_position);
}

void other_view_toggle_day_night(other_view_t *view) {
  lv_color_t color = ToolGetThemeColor();

  lv_obj_set_style_text_color(view->trip_key, color, 0);
  lv_obj_set_style_text_color(view->trip_value, color, 0);
  lv_obj_set_style_text_color(view->trip_unit, color, 0);
  lv_obj_set_style_text_color(view->avg_key, color, 0);
  lv_obj_set_style_text_color(view->avg_value, color, 0);
  lv_obj_set_style_text_color(view->avg_unit, color, 0);
  lv_obj_set_style_text_color(view->ride_time_key, color, 0);
  lv_obj_set_style_text_color(view->ride_time_value, color, 0);
  lv_obj_set_style_text_color(view->ride_time_unit, color, 0);
  lv_obj_set_style_text_color(view->battery_key, color, 0);
  lv_obj_set_style_text_color(view->battery_value, color, 0);
  lv_obj_set_style_text_color(view->battery_unit, color, 0);
}

void other_view_change_pos(lv_obj_t *value, lv_obj_t *unit, label_pos_t pos) {
  char *temp = lv_label_get_text(value);
  lv_point_t pos_temp;
  lv_coord_t letter_space =
      lv_obj_get_style_text_letter_space(value, LV_PART_MAIN);
  lv_coord_t width =
      lv_txt_get_width(temp, strlen(temp), tool_get_font(pos.font),
                       letter_space, LV_TEXT_FLAG_NONE);
  width = width + 10;
  lv_obj_set_pos(value, pos.x + 5, pos.y);
  lv_obj_set_width(value, width);

  lv_obj_set_x(unit, pos.x + width);
}