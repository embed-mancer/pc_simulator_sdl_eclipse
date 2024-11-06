#ifndef MOTOR_CONTROLLER_H_
#define MOTOR_CONTROLLER_H_

#include "../view/gear_view.h"
#include "../view/guage_view.h"
#include "../view/other_view.h"

void notify_gear(gear_view_t *view);
void notify_oil(guage_view_t *view);
void notify_water(guage_view_t *view);
void notify_other(other_view_t *view);

#endif  // MOTOR_CONTROLLER_H_
