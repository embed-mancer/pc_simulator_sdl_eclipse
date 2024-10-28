#include "light_model.h"
#include <stdio.h>

static int light_states[kLightCount] = {0};
static double voltage_ = 0.0;

int LightModelGetState(LightEnum state) {
  if (state >= 0 && state < kLightCount) {
    return light_states[state];
  }
  return -1;
}

void LightModelSetState(LightEnum state, int value) {
  if (state >= 0 && state < kLightCount) {
    light_states[state] = value;
  }
}

double LightModelGetVoltage() {
  return voltage_;
}

void LightModelSetVoltage(double voltage) {
  voltage_ = voltage;
}

#define LIGHT_MODEL_GETTER(name, state_enum) \
  int LightModel_Get##name() {               \
    return LightModelGetState(state_enum);  \
  }

LIGHT_MODEL_GETTER(Abs, kABS)

void LightModelInit() {
  for (int i = 0; i < kLightCount; i++) {
    light_states[i] = 0;
  }
  voltage_ = 0.0;
}
