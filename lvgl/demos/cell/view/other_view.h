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

  lv_obj_t *bg;

  image_pos pos_line_split;
  label_pos pos_trip_key;
  label_pos pos_trip_value;
  label_pos pos_trip_unit;
  label_pos pos_avg_key;
  label_pos pos_avg_value;
  label_pos pos_avg_unit;
  label_pos pos_ride_time_key;
  label_pos pos_ride_time_value;
  label_pos pos_ride_time_unit;
  label_pos pos_battery_key;
  label_pos pos_battery_value;
  label_pos pos_battery_unit;
} OtherView;


void OtherViewInit(OtherView *view);
void OtherViewCreate(OtherView *view);
void OtherViewUpdate(OtherView *view);
void OtherViewToggleDayNightMode(OtherView *view);
void OtherViewChangePos(lv_obj_t *value, lv_obj_t *unit, label_pos pos);

#endif // OTHER_VIEW_H_
