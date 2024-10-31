#include "other_view.h"

#include "../other/motor_model.h"

void OtherViewInit(OtherView *view) {
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
  OtherViewCreate(view);
  OtherViewUpdate(view);
}

void OtherViewCreate(OtherView *view) {
  view->line_split_position =
      CreateImagePos(RES_PRFIX "home/night/line_split.png", 33, 263);
  view->trip_key_position =
      CreateLabelPos(31, 234, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"小计里程"});
  view->trip_value_position =
      CreateLabelPos(142, 235, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextInt, (LabelValue)9999);
  view->trip_unit_position =
      CreateLabelPos(180, 235, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"km"});
  view->avg_key_position =
      CreateLabelPos(31, 273, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"平均车速"});
  view->avg_value_position =
      CreateLabelPos(142, 272, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextInt, (LabelValue)58);
  view->avg_unit_position =
      CreateLabelPos(180, 272, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"km"});
  view->ride_time_key_position =
      CreateLabelPos(31, 312, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"骑行时间"});
  view->ride_time_value_position =
      CreateLabelPos(142, 311, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"00:15"});
  view->ride_time_unit_position =
      CreateLabelPos(180, 311, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"h"});
  view->battery_key_position =
      CreateLabelPos(31, 352, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"电池电压"});
  view->battery_value_position =
      CreateLabelPos(142, 351, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextFloat, (LabelValue)12.0);
  view->battery_unit_position =
      CreateLabelPos(180, 351, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"V"});
  LightViewOne(view->background, &view->line_split, view->line_split_position);
  CreateLabel(view->background, &view->trip_key, view->trip_key_position);
  CreateLabel(view->background, &view->trip_value, view->trip_value_position);
  CreateLabel(view->background, &view->trip_unit, view->trip_unit_position);
  CreateLabel(view->background, &view->avg_key, view->avg_key_position);
  CreateLabel(view->background, &view->avg_value, view->avg_value_position);
  CreateLabel(view->background, &view->avg_unit, view->avg_unit_position);
  CreateLabel(view->background, &view->ride_time_key,
              view->ride_time_key_position);
  CreateLabel(view->background, &view->ride_time_value,
              view->ride_time_value_position);
  CreateLabel(view->background, &view->ride_time_unit,
              view->ride_time_unit_position);
  CreateLabel(view->background, &view->battery_key, view->battery_key_position);
  CreateLabel(view->background, &view->battery_value,
              view->battery_value_position);
  CreateLabel(view->background, &view->battery_unit,
              view->battery_unit_position);
}

void OtherViewUpdate(OtherView *view) {
  OtherViewChangePos(view->trip_value, view->trip_unit,
                     view->trip_value_position);
  OtherViewChangePos(view->avg_value, view->avg_unit, view->avg_value_position);
  OtherViewChangePos(view->ride_time_value, view->ride_time_unit,
                     view->ride_time_key_position);
  OtherViewChangePos(view->battery_value, view->battery_unit,
                     view->battery_value_position);
}

void OtherViewToggleDayNightMode(OtherView *view) {
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

void OtherViewChangePos(lv_obj_t *value, lv_obj_t *unit, LabelPos pos) {
  char *temp = lv_label_get_text(value);
  lv_point_t pos_temp;
  lv_coord_t letter_space =
      lv_obj_get_style_text_letter_space(value, LV_PART_MAIN);
  lv_coord_t width = lv_txt_get_width(temp, strlen(temp), ToolGetFont(pos.font),
                                      letter_space, LV_TEXT_FLAG_NONE);
  width = width + 10;
  lv_obj_set_pos(value, pos.x + 5, pos.y);
  lv_obj_set_width(value, width);

  lv_obj_set_x(unit, pos.x + width);
}
