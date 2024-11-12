#include "light_model.h"
#include <stdio.h>

static int g_light_states[SIGNAL_LIGHT_COUNT] = {0};
static double g_voltage = 0.0;

int ligth_model_get_state(signal_light_e state) {
  if (state >= 0 && state < SIGNAL_LIGHT_COUNT) {
    return g_light_states[state];
  }
  return -1;
}

void ligth_model_set_state(signal_light_e state, int value) {
  if (state >= 0 && state < SIGNAL_LIGHT_COUNT) {
    g_light_states[state] = value;
  }
}

double ligth_model_get_voltage(void) { return g_voltage; }

// Function to set the voltage
void ligth_model_set_voltage(double voltage) { g_voltage = voltage; }

// Macro to define a getter function for a specific light state
#define LIGHT_MODEL_GETTER(name, state_enum) \
  int LightModel_Get##name(void) { return ligth_model_get_state(state_enum); }

LIGHT_MODEL_GETTER(Abs, SIGNAL_LIGHT_ABS)

// Initialization function for light model
void light_model_init(void) {
  for (int i = 0; i < SIGNAL_LIGHT_COUNT; ++i) {
    g_light_states[i] = 0;
  }
  g_voltage = 0.0;
}
