#include "light_view.h"

void LightViewInit(LightView *view) {
  view->abs_ = NULL;
  view->turn_left_ = NULL;
  view->turn_right_ = NULL;
  view->high_beam_ = NULL;
  view->engine_fault_ = NULL;
  view->location_ = NULL;
  view->maintain_ = NULL;
  view->voltage_ = NULL;
}

void LightViewCreate(LightView *view) {
  LightViewOne(view->bg_, view->abs_, view->light->abs);
  LightViewOne(view->bg_, view->turn_left_, view->light->turn_left);
  LightViewOne(view->bg_, view->turn_right_, view->light->turn_right);
  LightViewOne(view->bg_, view->high_beam_, view->light->high_beam);
  LightViewOne(view->bg_, view->engine_fault_, view->light->engine_fault);
  LightViewOne(view->bg_, view->location_, view->light->location);
  LightViewOne(view->bg_, view->maintain_, view->light->maintain);
  LightViewOne(view->bg_, view->voltage_, view->light->voltage);
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

void LightViewHighBeam(LightView *view, DisplayTable table) {
  if (view->high_beam_)
    Display(view->high_beam_, table);
}

void LightViewEngine(LightView *view, DisplayTable table) {
  if (view->engine_fault_)
    Display(view->engine_fault_, table);
}

void LightViewLocation(LightView *view, DisplayTable table) {
  if (view->location_)
    Display(view->location_, table);
}

void LightViewMaintain(LightView *view, DisplayTable table) {
  if (view->maintain_)
    Display(view->maintain_, table);
}

void LightViewVoltage(LightView *view, DisplayTable table) {
  if (view->voltage_)
    Display(view->voltage_, table);
}

void LightViewOne(lv_obj_t *bg, lv_obj_t *lv, image_pos pos) {
  if (lv)
    return;
  lv = lv_img_create(bg);
  lv_obj_set_pos(lv, pos.x, pos.y);
  lv_img_set_src(lv, pos.image);
  // lv_obj_add_flag(lv, LV_OBJ_FLAG_HIDDEN);
}