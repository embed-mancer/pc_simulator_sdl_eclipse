#ifndef LIGHT_CONTROL_H_
#define LIGHT_CONTROL_H_

#include "light_view.h"

void ligth_control_init();
void ligth_control_icon(light_view_t *view, signal_light_e icon_type);
void ligth_control_all(light_view_t *view);
void ligth_control_check(light_view_t *view);
void ligth_control_voltage(light_view_t *view);

#endif  // LIGHT_CONTROL_H_
