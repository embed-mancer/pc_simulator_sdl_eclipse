#include "rpm_view.h"

#include "../other/motor_model.h"
#include "../tool/constrant.h"

static data_acc acc;

void RpmViewInit(RpmView *view) {
  view->line = NULL;
  view->num = NULL;
  view->unit = NULL;
  for (int i = 0; i < 110; ++i) view->block[i] = NULL;
  RpmViewCreate(view);
}

void RpmViewCreate(RpmView *view) {
  view->pos_line = CreateImagePos(RES_PRFIX "home/night/rpm/line.png", 0, 94);
  view->pos_num = CreateImagePos(RES_PRFIX "home/night/rpm/num.png", 5, 166);
  view->pos_unit = CreateImagePos(RES_PRFIX "home/night/rpm/unit.png", 713, 112);
  for (int i = 0; i < 110; ++i) {
    view->pos_block[i] = CreateImagePos("", 0, 122);
    snprintf(view->pos_block[i].image, sizeof(view->pos_block[i].image),
             RES_PRFIX "home/night/rpm/%d.png", i);
  }
  LightViewOne(view->bg, &view->line, view->pos_line);
  LightViewOne(view->bg, &view->num, view->pos_num);
  LightViewOne(view->bg, &view->unit, view->pos_unit);
  for (int i = 0; i < 110; ++i) {
    LightViewOne(view->bg, &view->block[i], view->pos_block[i]);
    lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  }
}

void RpmViewUpdate(RpmView *view, int value) {
  value = (value > kMaxRpm) ? kMaxRpm : value;
  if (value > 0) {
    int index;
    if (value % 100 == 0)
      index = value / 100 - 1;
    else
      index = value / 100;
    for (int i = 0; i <= index; i++)
      lv_obj_clear_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
    for (int i = index + 1; i < 110; i++)
      lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  } else {
    for (int i = 0; i < 110; ++i)
      lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  }
}

void RpmViewRun() {
  int data = MotorModelGetRpm();
  if (acc.current < data) {
    acc.current += acc.acc;
    if (acc.current > data) acc.current = data;
  } else if (acc.current > data) {
    acc.current -= acc.acc;
    if (acc.current < data) acc.current = data;
  }
}

int RpmViewCurrent() { return acc.current; }
