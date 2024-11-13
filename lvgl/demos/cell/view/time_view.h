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

  label_pos_t hour_digit1_position;
  label_pos_t hour_digit2_position;
  label_pos_t colon_position;
  label_pos_t minute_digit1_position;
  label_pos_t minute_digit2_position;
} time_view_t;

void time_view_init(time_view_t *view, lv_obj_t *background);
void time_view_create(time_view_t* view);
void time_view_update(time_view_t* view);
void time_view_toggle_day_night(time_view_t* view);

#endif  // TIME_VIEW_H_
