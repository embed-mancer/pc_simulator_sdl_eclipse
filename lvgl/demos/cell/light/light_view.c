#include "light_view.h"

void LightViewInit(LightView *view) {
  view->abs_ = NULL;
  view->turn_left_ = NULL;
  view->turn_right_ = NULL;
}

void LightViewCreate(LightView *view) {
  LightViewOne(view, view->abs_, view->light->abs);
  LightViewOne(view, view->turn_left_, view->light->turn_left);
  LightViewOne(view, view->turn_right_, view->light->turn_right);
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

void LightViewTurnLeft(LightView *view, DisplayTable table) {
  if (view->turn_left_)
    Display(view->turn_left_, table);
}

void LightViewTurnRight(LightView *view, DisplayTable table) {
  if (view->turn_right_)
    Display(view->turn_right_, table);
}

void LightViewAbs(LightView *view, DisplayTable table) {
  if (view->abs_)
    Display(view->abs_, table);
}

void LightViewOne(LightView *view, lv_obj_t *lv, image_pos pos) {
  if (lv)
    return;
  lv = lv_img_create(view->bg_);
  lv_obj_set_pos(lv, pos.x, pos.y);
  lv_img_set_src(lv, pos.image);
  // lv_obj_add_flag(lv, LV_OBJ_FLAG_HIDDEN);

}