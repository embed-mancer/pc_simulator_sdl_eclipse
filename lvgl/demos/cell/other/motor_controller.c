#include "motor_controller.h"
#include "motor_model.h"
#include "../view/guage_view.h"

void NotifyGear(GearView *view) {
  int value = MotorModelGetGear();
  GearViewUpdate(view, value);
}

void NotifyOil(GuageView *view) {
  int value = MotorModelGetOil();
  GuageViewUpdate(view, value);
}
