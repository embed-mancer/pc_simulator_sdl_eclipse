#ifndef LIGHT_CONTROL_H_
#define LIGHT_CONTROL_H_

#include "light_view.h"

void LightControlInit();
void LightControlIcon(LightView *view, LightEnum icon_type);
void LightControlAll(LightView *view);
void LightControlCheck(LightView *view);
void LightControlVoltage(LightView *view);

#endif  // LIGHT_CONTROL_H_
