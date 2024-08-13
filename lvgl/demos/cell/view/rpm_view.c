#include "rpm_view.h"
#include "../other/motor_model.h"

static data_acc acc;

void RpmViewInit(RpmView *view) {
  view->icon = NULL;
  view->line = NULL;
  for (int i = 0; i < 24; ++i)
    view->block[i] = NULL;
  for (int i = 0; i < 7; ++i)
    view->num[i] = NULL;
}

void RpmViewCreate(RpmView *view) {
  for (int i = 0; i < 7; ++i) {
    LightViewOne(view->bg, &view->num[i], view->pos_num[i]);
  }
  LightViewOne(view->bg, &view->icon, view->pos_icon);
  LightViewOne(view->bg, &view->line, view->pos_line); 
  for (int i = 0; i < 24; ++i) {
    LightViewOne(view->bg, &view->block[i], view->pos_block[i]);
    lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  }
}

void RpmViewUpdate(RpmView *view, int value) {
  if (value > 0) {
    int index;
    if (value % 500 == 0)
      index = value / 500 - 1;
    else
      index = value / 500;
    for (int i = 0; i <= index; i++)
      lv_obj_clear_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
    for (int i = index+1; i < 24; i++)
      lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  } else {
    for (int i = 0; i < 24; ++i) 
      lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  }
}

void RpmViewRun() {
  int data = MotorModelGetRpm();
  if (acc.current < data) {
    acc.current += acc.acc;
    if (acc.current > data)
      acc.current = data;
  } else if (acc.current > data) {
    acc.current -= acc.acc;
    if (acc.current < data)
      acc.current = data;
  }
}

int RpmViewCurrent() {
  return acc.current;
}