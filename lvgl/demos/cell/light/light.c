#include "light.h"

Light light_main = {
  .pos[kTurnLeft] = {.x = 25, .y = 17, .image = RES_PRFIX"home/light/turn_left.png" },
  .pos[kAutoStartStop] = {.x = 96, .y = 13, .image = RES_PRFIX"home/light/auto_start_stop.png" },
  .pos[kTire] = {.x = 167, .y = 13, .image = RES_PRFIX"home/light/tire.png" },
  .pos[kHighBeam] = {.x = 237, .y = 13, .image = RES_PRFIX"home/light/high_beam.png" },
  .pos[kOilPressure] = {.x = 312, .y = 13, .image = RES_PRFIX"home/light/oil_pressure.png" },
  .pos[kABS] = {.x = 395, .y = 13, .image = RES_PRFIX"home/light/abs.png" },
  .pos[kEngineFault] = {.x = 469, .y = 13, .image = RES_PRFIX"home/light/engine_fault.png" },
  .pos[kWifi] = {.x = 542, .y = 13, .image = RES_PRFIX"home/light/wifi.png" },
  .pos[kBtPair] = {.x = 611, .y = 13, .image = RES_PRFIX"home/light/bt_pair.png" },
  .pos[kBtIcon] = {.x = 673, .y = 12, .image = RES_PRFIX"home/light/bt_icon.png" },
  .pos[kTurnRight] = {.x = 739, .y = 16, .image = RES_PRFIX"home/light/turn_right.png" },
  .pos[kVoltage]= {.x = 28, .y = 85, .image = RES_PRFIX"home/light/voltage.png" },
};

void LightInit() {
}
