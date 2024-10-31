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

  ImagePos line_split_position;
  LabelPos trip_key_position;
  LabelPos trip_value_position;
  LabelPos trip_unit_position;
  LabelPos avg_key_position;
  LabelPos avg_value_position;
  LabelPos avg_unit_position;
  LabelPos ride_time_key_position;
  LabelPos ride_time_value_position;
  LabelPos ride_time_unit_position;
  LabelPos battery_key_position;
  LabelPos battery_value_position;
  LabelPos battery_unit_position;
} OtherView;

void OtherViewInit(OtherView *view);
void OtherViewCreate(OtherView *view);
void OtherViewUpdate(OtherView *view);
void OtherViewToggleDayNightMode(OtherView *view);
void OtherViewChangePos(lv_obj_t *value, lv_obj_t *unit, LabelPos pos);

#endif  // OTHER_VIEW_H_
