#include "light_controller.h"
#include "light_model.h"

void LightNotifyAbs(LightView *view) {
  int value = light_model_get_abs();
  if (value == 1)
    LightViewAbs(view, kShow);
  else if (value == 0)
    LightViewAbs(view, kHide);
}

void LightNotifyTurnLeft(LightView *view) {
  int value = light_model_get_turn_left();
  if (value == 1)
    LightViewTurnLeft(view, kShow);
  else if (value == 0)
    LightViewTurnLeft(view, kHide);
}

void LightNotifyTurnRight(LightView *view) {
  int value = light_model_get_turn_right();
  if (value == 1)
    LightViewTurnRight(view, kShow);
  else if (value == 0)
    LightViewTurnRight(view, kHide);
}