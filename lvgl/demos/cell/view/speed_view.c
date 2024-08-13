#include "speed_view.h"
#include "../other/motor_model.h"

static data_acc acc;

void SpeedViewInit(SpeedView *view) {
  view->unit = NULL;
  for (int i = 0; i < 3; ++i)
    view->block[i] = NULL;
}

void SpeedViewCreate(SpeedView *view) {
  for (int i = 0; i < 3; ++i) {
    LightViewOne(view->bg, &view->block[i], view->pos_block[i]);
  }
  LightViewOne(view->bg, &view->unit, view->pos_unit);
  lv_obj_add_flag(view->block[0], LV_OBJ_FLAG_HIDDEN);
  lv_obj_add_flag(view->block[1], LV_OBJ_FLAG_HIDDEN);
  SpeedViewUpdate(view, 0);
}

void SpeedViewUpdate(SpeedView *view, int value) {
  int mid = 612;
  int width = 128;
  if (value < 10) {
    lv_obj_set_x(view->block[2], mid-width/2);
    lv_obj_add_flag(view->block[0], LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(view->block[1], LV_OBJ_FLAG_HIDDEN);
    lv_img_set_src(view->block[2], view->sz_block[value]);
  } else if (value < 100) {
    lv_obj_set_x(view->block[1], mid-width);
    lv_obj_set_x(view->block[2], mid);
    lv_obj_add_flag(view->block[0], LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(view->block[1], LV_OBJ_FLAG_HIDDEN);
    lv_img_set_src(view->block[1], view->sz_block[value/10]);
    lv_img_set_src(view->block[2], view->sz_block[value%10]);
  } else {
    lv_obj_set_x(view->block[0], mid-3*width/2-5);
    lv_obj_set_x(view->block[1], mid-width/2-30);
    lv_obj_set_x(view->block[2], mid+width/2-25);
    lv_obj_clear_flag(view->block[0], LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(view->block[1], LV_OBJ_FLAG_HIDDEN);
    lv_img_set_src(view->block[0], view->sz_block[value/100]);
    lv_img_set_src(view->block[1], view->sz_block[value/10%10]);
    lv_img_set_src(view->block[2], view->sz_block[value%10]);
  }
}

void SpeedViewRun() {
  int data = MotorModelSpeed();
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

int SpeedViewCurrent() {
  return acc.current;
}