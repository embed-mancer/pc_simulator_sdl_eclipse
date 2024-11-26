#include "light_control.h"
#include "light_model.h"

#define DEFINE_LIGHT_CONTROL_FUNC(name, icon_t)   \
  void light_control_##name(light_view_t *view) { \
    light_control_icon(view, icon_t);             \
  }

DEFINE_LIGHT_CONTROL_FUNC(turn_left, SIGNAL_LIGHT_TURN_LEFT)
DEFINE_LIGHT_CONTROL_FUNC(turn_right, SIGNAL_LIGHT_TURN_RIGHT)
DEFINE_LIGHT_CONTROL_FUNC(auto_start_stop, SIGNAL_LIGHT_AUTO_START_STOP)
DEFINE_LIGHT_CONTROL_FUNC(high_beam, SIGNAL_LIGHT_HIGH_BEAM)
DEFINE_LIGHT_CONTROL_FUNC(tire, SIGNAL_LIGHT_TIRE)
DEFINE_LIGHT_CONTROL_FUNC(abs, SIGNAL_LIGHT_ABS)
DEFINE_LIGHT_CONTROL_FUNC(oil_pressure, SIGNAL_LIGHT_OIL_PRESSURE)
DEFINE_LIGHT_CONTROL_FUNC(engine_fault, SIGNAL_LIGHT_ENGINE_FAULT)
DEFINE_LIGHT_CONTROL_FUNC(wifi, SIGNAL_LIGHT_WIFI)
DEFINE_LIGHT_CONTROL_FUNC(bt_icon, SIGNAL_LIGHT_BT_ICON)
DEFINE_LIGHT_CONTROL_FUNC(bt_pair, SIGNAL_LIGHT_BT_PAIR)

void light_control_init() {
}

void light_control_icon(light_view_t *view, signal_light_e icon_type) {
  int state = light_model_get_state(icon_type) ? DISPLAY_STATE_SHOW
                                               : DISPLAY_STATE_HIDE;
  light_view_display(&view->icons[icon_type], state);
}

void light_control_all(light_view_t *view) {
  light_control_turn_left(view);
  light_control_turn_right(view);
  light_control_auto_start_stop(view);
  light_control_high_beam(view);
  light_control_tire(view);
  light_control_abs(view);
  light_control_oil_pressure(view);
  light_control_engine_fault(view);
  light_control_wifi(view);
  light_control_bt_icon(view);
  light_control_bt_pair(view);
  light_control_voltage(view);
}

void light_control_check(light_view_t *view) {
  for (size_t i = 0; i <= SIGNAL_LIGHT_VOLTAGE; ++i)
    light_view_display(&view->icons[i], DISPLAY_STATE_SHOW);
  light_view_display(&view->icons[SIGNAL_LIGHT_VOLTAGE], DISPLAY_STATE_SHOW);
}

void light_control_voltage(light_view_t *view) {
  double voltage = light_model_get_voltage();
  if (voltage < 11.3)
    light_view_display(&view->icons[SIGNAL_LIGHT_VOLTAGE], DISPLAY_STATE_HIDE);
  else
    light_view_display(&view->icons[SIGNAL_LIGHT_VOLTAGE], DISPLAY_STATE_SHOW);
}
