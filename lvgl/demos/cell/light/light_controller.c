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

void LightNotifyHighBeam(LightView *view) {
  int value = light_model_get_high_beam();
  if (value == 1)
    LightViewHighBeam(view, kShow);
  else
    LightViewHighBeam(view, kHide);
}

void LightNotifyEngine(LightView *view) {
  int value = light_model_get_engine_fault();
  if (value == 1)
    LightViewEngine(view, kShow);
  else
    LightViewEngine(view, kHide);
}

void LightNotifyLocation(LightView *view) {
  int value = light_model_get_location();
  if (value == 1)
    LightViewLocation(view, kShow);
  else
    LightViewLocation(view, kHide);
}

void LightNotifyMaintain(LightView *view) {
  int value = light_model_get_maintain();
  if (value == 1)
    LightViewMaintain(view, kShow);
  else
    LightViewMaintain(view, kHide);
}

void LightNotifyVoltage(LightView *view) {
  int value = light_model_get_voltage();
  if (value == 1)
    LightViewVoltage(view, kShow);
  else
    LightViewVoltage(view, kHide);
}

void LightNotifyAll(LightView *view) {
  LightNotifyTurnLeft(view);
  LightNotifyAbs(view);
  LightNotifyTurnRight(view);
  LightNotifyHighBeam(view);
  LightNotifyEngine(view);
  LightNotifyLocation(view);
  LightNotifyMaintain(view);
  LightNotifyVoltage(view);
}

void LightCheck(LightView *view) {
  LightViewTurnLeft(view, kShow);
  LightViewAbs(view, kShow);
  LightViewTurnRight(view, kShow);
  LightViewHighBeam(view, kShow);
  LightViewEngine(view, kShow);
  LightViewLocation(view, kShow);
  LightViewMaintain(view, kShow);
  LightViewVoltage(view, kShow);
}