#include "motor_controller.h"
#include "motor_model.h"

void NotifyGear(GearView *view) {
  int value = MotorModelGetGear();
  GearViewUpdate(view, value);
}

void NotifyOil(GuageView *view) {
  int value = MotorModelGetOil();
  GuageViewUpdate(view, value);
}

void NotifyWater(GuageView *view) {
  int value = MotorModelGetWater();
  GuageViewUpdate(view, value);
}

void NotifyOther(OtherView *view) {
  OtherViewUpdate(view);
}
