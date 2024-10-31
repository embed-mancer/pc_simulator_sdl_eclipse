#ifndef TIME_VIEW_H_
#define TIME_VIEW_H_

#include "../cell.h"
#include "../light/light_view.h"

typedef struct {
  lv_obj_t* background;
  lv_obj_t* hour_digit1;
  lv_obj_t* hour_digit2;
  lv_obj_t* colon;
  lv_obj_t* minute_digit1;
  lv_obj_t* minute_digit2;

  LabelPos hour_digit1_position;
  LabelPos hour_digit2_position;
  LabelPos colon_position;
  LabelPos minute_digit1_position;
  LabelPos minute_digit2_position;
} TimeView;

void TimeViewInit(TimeView* view);
void TimeViewCreate(TimeView* view);
void TimeViewUpdate(TimeView* view);
void TimeViewToggleDayNightMode(TimeView* view);

#endif  // TIME_VIEW_H_
