#ifndef LIGHT_MODEL_H_
#define LIGHT_MODEL_H_

#include "../tool/enums.h"

void light_model_init();
int ligth_model_get_state(signal_light_t state);
void ligth_model_set_state(signal_light_t state, int value);
double ligth_model_get_voltage();
void ligth_model_set_voltage(double voltage);

#endif  // LIGHT_MODEL_H_
