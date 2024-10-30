#ifndef GEAR_VIEW_H_
#define GEAR_VIEW_H_

#include "../light/light.h"
#include "../cell.h"

typedef struct {
  lv_obj_t *key;
  lv_obj_t *value;
  lv_obj_t *bg_;
  label_pos pos_key;
  label_pos pos_value;
} GearView;

void GearViewInit(GearView *view);
void GearViewCreate(GearView *view);
void GearViewUpdate(GearView *view, int value);

#endif // GEAR_VIEW_H_
