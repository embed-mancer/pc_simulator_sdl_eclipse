#ifndef LIGHT_MODEL_H_
#define LIGHT_MODEL_H_

#include "../tool/enums.h"

void light_model_init();
int light_model_get_state(signal_light_e state);
void light_model_set_state(signal_light_e state, int value);
double light_model_get_voltage();
void light_model_set_voltage(double voltage);
void light_model_set_all();

#endif  // LIGHT_MODEL_H_
