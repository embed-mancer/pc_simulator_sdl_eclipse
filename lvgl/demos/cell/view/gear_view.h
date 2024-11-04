#ifndef GEAR_VIEW_H_
#define GEAR_VIEW_H_

#include "../cell.h"
#include "../light/light.h"

typedef struct {
  lv_obj_t *key;
  lv_obj_t *value;
  lv_obj_t *background;
  LabelPos key_position;
  LabelPos value_position;
} GearView;

void GearViewInit(GearView *view);
void GearViewCreate(GearView *view);
void GearViewUpdate(GearView *view, int value);
void GearViewToggleDayNightMode(GearView *view);

#endif  // GEAR_VIEW_H_
