#include "oil_view.h"

void OilViewInit(OilView *view, OilViewMode mode) {
  view->icon = NULL;
  view->line = NULL;
  view->block[0] = NULL;
  view->E = NULL;
  view->F = NULL;
  view->mode = mode;
  view->max_oil_value = kOilNum;
  for (int i = 0; i < kOilNum; ++i) 
    view->block[i] = NULL;
  OilViewCreate(view);
}

void OilViewCreate(OilView *view) {
  if (view->bg == NULL) {
    return;
  }
  if (view->mode == kOilViewModeBlock) {
    for (int i = 0; i < kOilNum; ++i) {
      LightViewOne(view->bg, &view->block[i], view->pos_block[i]);
      lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
    }
    LightViewOne(view->bg, &view->icon, view->pos_icon);
    LightViewOne(view->bg, &view->line, view->pos_line);
  } else if (view->mode == kOilViewModeWidth) {
    LightViewOne(view->bg, &view->icon, view->pos_icon);
    LightViewOne(view->bg, &view->line, view->pos_line);
    view->block[0] = lv_img_create(view->bg);
    lv_img_set_src(view->block[0], view->pos_block[0].image);
    lv_obj_set_pos(view->block[0], view->pos_block[0].x, view->pos_block[0].y);
    lv_obj_set_width(view->block[0], 20);
    Label(view->bg, &view->E, view->pos_E);
    Label(view->bg, &view->F, view->pos_F);
  }
}

void OilViewUpdate(OilView *view, int value) {
  if (value < 0) {
    value = 0;
  }
  if (value > view->max_oil_value) {
    value = view->max_oil_value;
  }

  if (view->mode == kOilViewModeBlock) {
    if (value <= 0) {
      for (int i = 0; i < kOilNum; ++i)
        lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
    } else {
      for (int i = 0; i < value; i++)
        lv_obj_clear_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
      for (int i = value; i < kOilNum; ++i)
        lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
    }
  } else if (view->mode == kOilViewModeWidth) {
    int block_width = 10;
    lv_obj_set_size(view->block[0], block_width, 8);
  }
}
