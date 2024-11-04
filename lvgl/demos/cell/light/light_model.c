#include "light_model.h"
#include <stdio.h>

static int g_light_states[kLightCount] = {0};
static double g_voltage = 0.0;

int LightModelGetState(LightEnum state) {
  if (state >= 0 && state < kLightCount) {
    return g_light_states[state];
  }
  return -1;
}

void LightModelSetState(LightEnum state, int value) {
  if (state >= 0 && state < kLightCount) {
    g_light_states[state] = value;
  }
}

double LightModelGetVoltage(void) { return g_voltage; }

// Function to set the voltage
void LightModelSetVoltage(double voltage) { g_voltage = voltage; }

// Macro to define a getter function for a specific light state
#define LIGHT_MODEL_GETTER(name, state_enum) \
  int LightModel_Get##name(void) { return LightModelGetState(state_enum); }

LIGHT_MODEL_GETTER(Abs, kABS)

// Initialization function for light model
void LightModelInit(void) {
  for (int i = 0; i < kLightCount; ++i) {
    g_light_states[i] = 0;
  }
  g_voltage = 0.0;
}
