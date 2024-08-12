#include "oil_view.h"

void OilViewInit(OilView *view) {
  view->icon = NULL;
  view->line = NULL;
  for (int i = 0; i < 8; ++i)
    view->block[i] = NULL;
}

void OilViewCreate(OilView *view) {
  for (int i = 0; i < 8; ++i) {
    LightViewOne(view->bg, &view->block[i], view->pos_block[i]);
  }
  LightViewOne(view->bg, &view->icon, view->pos_icon);
  LightViewOne(view->bg, &view->line, view->pos_line);
}

void OilViewUpdate(OilView *view, int value) {
  if (value == 0) {
    for (int i = 0; i < 8; ++i)
      lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  } else {
    int index = value - 1;
    for (int i = 0; i <= index; i++)
      lv_obj_clear_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
    for (int i = index + 1; i < 8; ++i)
      lv_obj_add_flag(view->block[i], LV_OBJ_FLAG_HIDDEN);
  }
}