#include "light.h"
#include "../tool/enums.h"

#define INIT_ICON(index, pos_x, pos_y, image_src) \
  .pos[index] = {.x = pos_x, .y = pos_y, .image = image_src}

Light light_main = {
    INIT_ICON(kTurnLeft, 25, 17, RES_PRFIX "home/light/turn_left.png"),
    INIT_ICON(kAutoStartStop, 96, 13,
              RES_PRFIX "home/light/auto_start_stop.png"),
    INIT_ICON(kTire, 167, 13, RES_PRFIX "home/light/tire.png"),
    INIT_ICON(kHighBeam, 237, 13, RES_PRFIX "home/light/high_beam.png"),
    INIT_ICON(kOilPressure, 312, 13, RES_PRFIX "home/light/oil_pressure.png"),
    INIT_ICON(kABS, 395, 13, RES_PRFIX "home/light/abs.png"),
    INIT_ICON(kEngineFault, 469, 13, RES_PRFIX "home/light/engine_fault.png"),
    INIT_ICON(kWifi, 542, 13, RES_PRFIX "home/light/wifi.png"),
    INIT_ICON(kBtPair, 611, 13, RES_PRFIX "home/light/bt_pair.png"),
    INIT_ICON(kBtIcon, 673, 12, RES_PRFIX "home/light/bt_icon.png"),
    INIT_ICON(kTurnRight, 739, 16, RES_PRFIX "home/light/turn_right.png"),
    INIT_ICON(kVoltage, 28, 85, RES_PRFIX "home/light/voltage.png"),
};

void LightInit() {
}
