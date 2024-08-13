#include "motor_controller.h"
#include "motor_model.h"

void NotifyGear(GearView *view) {
  int value = MotorModelGetGear();
  GearViewUpdate(view, value);
}

void NotifyOil(OilView *view) {
  int value = MotorModelGetOil();
  OilViewUpdate(view, value);
}
