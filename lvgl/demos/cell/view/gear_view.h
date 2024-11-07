#ifndef GEAR_VIEW_H_
#define GEAR_VIEW_H_

#include "../cell.h"
#include "../light/light.h"

typedef struct {
  lv_obj_t *key;
  lv_obj_t *value;
  lv_obj_t *background;
  label_pos_t key_position;
  label_pos_t value_position;
} gear_view_t;

void gear_view_init(gear_view_t *view);
void gear_view_create(gear_view_t *view);
void gear_view_update(gear_view_t *view, int value);
void gear_view_toggle_day_night(gear_view_t *view);

#endif  // GEAR_VIEW_H_
