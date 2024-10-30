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
  OtherViewCreate(view);
  OtherViewUpdate(view);
}

void OtherViewCreate(OtherView *view) {
  view->pos_trip_key =
      CreateLabelPos(31, 234, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"小计里程"});
  view->pos_trip_value =
      CreateLabelPos(142, 235, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextInt, (LabelValue)9999);
  view->pos_trip_unit =
      CreateLabelPos(180, 235, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"km"});
  view->pos_avg_key =
      CreateLabelPos(31, 273, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"平均车速"});
  view->pos_avg_value =
      CreateLabelPos(142, 272, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextInt, (LabelValue)58);
  view->pos_avg_unit =
      CreateLabelPos(180, 272, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"km"});
  view->pos_ride_time_key =
      CreateLabelPos(31, 312, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"骑行时间"});
  view->pos_ride_time_value =
      CreateLabelPos(142, 311, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"00:15"});
  view->pos_ride_time_unit =
      CreateLabelPos(180, 311, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"h"});
  view->pos_battery_key =
      CreateLabelPos(31, 352, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"电池电压"});
  view->pos_battery_value =
      CreateLabelPos(142, 351, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextFloat, (LabelValue)12.0);
  view->pos_battery_unit =
      CreateLabelPos(180, 351, 100, 25, kColorWhite, kMicrosoftYaHei_20,
                     kTextChar, (LabelValue){"V"});
  Label(view->bg, &view->trip_key, view->pos_trip_key);
  Label(view->bg, &view->trip_value, view->pos_trip_value);
  Label(view->bg, &view->trip_unit, view->pos_trip_unit);
  Label(view->bg, &view->avg_key, view->pos_avg_key);
  Label(view->bg, &view->avg_value, view->pos_avg_value);
  Label(view->bg, &view->avg_unit, view->pos_avg_unit);
  Label(view->bg, &view->ride_time_key, view->pos_ride_time_key);
  Label(view->bg, &view->ride_time_value, view->pos_ride_time_value);
  Label(view->bg, &view->ride_time_unit, view->pos_ride_time_unit);
  Label(view->bg, &view->battery_key, view->pos_battery_key);
  Label(view->bg, &view->battery_value, view->pos_battery_value);
  Label(view->bg, &view->battery_unit, view->pos_battery_unit);
}

void OtherViewUpdate(OtherView *view) {
  OtherViewChangePos(view->trip_value, view->trip_unit, view->pos_trip_value);
  OtherViewChangePos(view->avg_value, view->avg_unit, view->pos_avg_value);
  OtherViewChangePos(view->ride_time_value, view->ride_time_unit,
                     view->pos_ride_time_value);
  OtherViewChangePos(view->battery_value, view->battery_unit,
                     view->pos_battery_value);
}

void OtherViewSetTheme(OtherView *view) {
  lv_color_t color =
      MotorModelGetTheme() == kDay ? lv_color_black() : lv_color_white();

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

void OtherViewChangePos(lv_obj_t *value, lv_obj_t *unit, label_pos pos) {
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
