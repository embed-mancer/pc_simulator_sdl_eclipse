#include "light_view.h"

void LightViewInit(LightView *view) {
  for (int i = 0; i < sizeof(view->icons) / sizeof(view->icons[0]); i++) {
    view->icons[i].obj = NULL;
    view->icons[i].is_needed = false;
  }
  view->icons[kTurnLeft].is_needed = true;
  view->icons[kTurnRight].is_needed = true;
  LightViewCreate(view);
}

void LightViewCreate(LightView *view) {
  for (int i = 0; i < sizeof(view->icons) / sizeof(view->icons[0]); i++) {
    if (view->icons[i].is_needed) {
      LightViewOne(view->bg_, &view->icons[i].obj, view->light->pos[i]);
    }
  }
}

void Display(lv_obj_t *control, DisplayTable table) {
  switch (table) {
    case kHide:
      lv_obj_add_flag(control, LV_OBJ_FLAG_HIDDEN);
      break;
    case kShow:
      lv_obj_clear_flag(control, LV_OBJ_FLAG_HIDDEN);
      break;
  }
}

void LightViewOne(lv_obj_t *bg, lv_obj_t **lv, image_pos pos) {
  if (*lv) return;
  *lv = lv_img_create(bg);
  lv_obj_set_pos(*lv, pos.x, pos.y);
  lv_img_set_src(*lv, pos.image);
}
