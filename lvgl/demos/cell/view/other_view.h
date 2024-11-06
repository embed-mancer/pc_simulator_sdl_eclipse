#ifndef OTHER_VIEW_H_
#define OTHER_VIEW_H_

#include "../cell.h"

typedef struct {
  lv_obj_t *line_split;

  lv_obj_t *trip_key;
  lv_obj_t *trip_value;
  lv_obj_t *trip_unit;

  lv_obj_t *avg_key;
  lv_obj_t *avg_value;
  lv_obj_t *avg_unit;

  lv_obj_t *ride_time_key;
  lv_obj_t *ride_time_value;
  lv_obj_t *ride_time_unit;

  lv_obj_t *battery_key;
  lv_obj_t *battery_value;
  lv_obj_t *battery_unit;

  lv_obj_t *background;

  image_pos_t line_split_position;
  label_pos_t trip_key_position;
  label_pos_t trip_value_position;
  label_pos_t trip_unit_position;
  label_pos_t avg_key_position;
  label_pos_t avg_value_position;
  label_pos_t avg_unit_position;
  label_pos_t ride_time_key_position;
  label_pos_t ride_time_value_position;
  label_pos_t ride_time_unit_position;
  label_pos_t battery_key_position;
  label_pos_t battery_value_position;
  label_pos_t battery_unit_position;
} other_view_t;

void other_view_init(other_view_t *view);
void other_view_create(other_view_t *view);
void other_view_update(other_view_t *view);
void other_view_toggle_day_night_mode(other_view_t *view);
void other_view_change_pos(lv_obj_t *value, lv_obj_t *unit, label_pos_t pos);

#endif  // OTHER_VIEW_H_
