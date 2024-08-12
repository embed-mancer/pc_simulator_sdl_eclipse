#include "water_view.h"


void WaterViewInit(WaterView *view) {
  view->icon = NULL;
  view->line = NULL;
  for (int i = 0; i < kWaterNum; ++i)
    view->block[i] = NULL;
}

void WaterViewCreate(WaterView *view) {
  for (int i = 0; i < kWaterNum; ++i) {
    LightViewOne(view->bg, &view->block[i], view->pos_block[i]);
  }
  LightViewOne(view->bg, &view->icon, view->pos_icon);
  LightViewOne(view->bg, &view->line, view->pos_line);
}

void WaterViewUpdate(WaterView *view, int value) {
  if (value == 0) {
    for (int i = 0; i < kWaterNum; ++i)
      lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  } else if (value < kWaterNum) {
    int index = value - 1;
    for (int i = 0; i <= index; i++)
      lv_obj_clear_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
    for (int i = index + 1; i < kWaterNum; ++i)
      lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  }
}