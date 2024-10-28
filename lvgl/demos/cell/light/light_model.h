#ifndef LIGHT_MODEL_H_
#define LIGHT_MODEL_H_

#include "../tool/enums.h"

void LightModelInit();
int LightModelGetState(LightEnum state);
void LightModelSetState(LightEnum state, int value);
double LightModelGetVoltage();
void LightModelSetVoltage(double voltage);

#endif // LIGHT_MODEL_H_
