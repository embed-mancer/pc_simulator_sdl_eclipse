#include "light_control.h"
#include "light_model.h"

#define DEFINE_LIGHT_CONTROL_FUNC(name, icon) \
  void LightControl##name(LightView *view) {  \
    LightControlIcon(view, icon);             \
  }

DEFINE_LIGHT_CONTROL_FUNC(TurnLeft, kTurnLeft)
DEFINE_LIGHT_CONTROL_FUNC(TurnRight, kTurnRight)
DEFINE_LIGHT_CONTROL_FUNC(AutoStartStop, kAutoStartStop)
DEFINE_LIGHT_CONTROL_FUNC(HighBeam, kHighBeam)
DEFINE_LIGHT_CONTROL_FUNC(Tire, kTire)
DEFINE_LIGHT_CONTROL_FUNC(Abs, kABS)
DEFINE_LIGHT_CONTROL_FUNC(OilPressure, kOilPressure)
DEFINE_LIGHT_CONTROL_FUNC(EngineFault, kEngineFault)
DEFINE_LIGHT_CONTROL_FUNC(Wifi, kWifi)
DEFINE_LIGHT_CONTROL_FUNC(BtIcon, kBtIcon)
DEFINE_LIGHT_CONTROL_FUNC(BtPair, kBtPair)

void LightControlInit() {
}

void LightControlIcon(LightView *view, LightEnum icon_type) {
  int state = LightModelGetState(icon_type) ? kShow : kHide;
  LightViewDisplay(&view->icons[icon_type], state);
}

void LightControlCheck(LightView *view) {
  LightViewDisplay(&view->icons[kABS], kShow);
}

void LightControlAll(LightView *view) {
  LightControlTurnLeft(view);
  LightControlTurnRight(view);
  LightControlAutoStartStop(view);
  LightControlHighBeam(view);
  LightControlTire(view);
  LightControlAbs(view);
  LightControlOilPressure(view);
  LightControlEngineFault(view);
  LightControlWifi(view);
  LightControlBtIcon(view);
  LightControlBtPair(view);
}
