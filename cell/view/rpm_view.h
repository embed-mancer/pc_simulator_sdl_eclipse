#ifndef RPM_VIEW_H_
#define RPM_VIEW_H_

#include "../cell.h"

typedef struct {
  lv_obj_t *line;
  lv_obj_t *num;
  lv_obj_t *unit;
  lv_obj_t *block;
  lv_obj_t *background;
  image_pos_t line_position;
  image_pos_t number_position;
  image_pos_t unit_position;
  image_pos_t block_positions[110];
  int last_index;
} rpm_view_t;

void rpm_view_init(rpm_view_t *view, lv_obj_t *background);
void rpm_view_create(rpm_view_t *view);
void rpm_view_update(rpm_view_t *view, uint16_t value);
void rpm_view_toggle_day_night(rpm_view_t *view);
void rpm_view_run();
int rpm_view_current();

#endif  // RPM_VIEW_H_
