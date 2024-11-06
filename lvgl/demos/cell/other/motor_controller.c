#include "motor_controller.h"
#include "motor_model.h"

void notify_gear(gear_view_t *view) {
  int value = motor_model_get_gear();
  gear_view_update(view, value);
}

void notify_oil(guage_view_t *view) {
  int value = motor_model_get_oil();
  guage_view_update(view, value);
}

void notify_water(guage_view_t *view) {
  int value = motor_model_get_water();
  guage_view_update(view, value);
}

void notify_other(other_view_t *view) { other_view_update(view); }