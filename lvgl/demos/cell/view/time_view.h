#ifndef TIME_VIEW_H_
#define TIME_VIEW_H_

#include "../cell.h"
#include "../light/light_view.h"

typedef struct {
  lv_obj_t *bg;
  lv_obj_t *time_hour1;
  lv_obj_t *time_hour2;
  lv_obj_t *time_colon;
  lv_obj_t *time_minute1;
  lv_obj_t *time_minute2;

  LabelPos pos_time_hour1;
  LabelPos pos_time_hour2;
  LabelPos pos_time_colon;
  LabelPos pos_time_minute1;
  LabelPos pos_time_minute2;
} TimeView;

void TimeViewInit(TimeView *view);
void TimeViewCreate(TimeView *view);
void TimeViewUpdate(TimeView *view);
void TimeViewToggleDayNightMode(TimeView *view);

#endif  // TIME_VIEW_H_
