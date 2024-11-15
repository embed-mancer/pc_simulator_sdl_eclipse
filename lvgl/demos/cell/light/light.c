#include "light.h"
#include "../tool/enums.h"

#define INIT_ICON(index, pos_x, pos_y, image_src) \
  .pos[index] = {.x = pos_x, .y = pos_y, .image = image_src}

light light_main = {
    INIT_ICON(SIGNAL_LIGHT_TURN_LEFT, 25, 17,
              RES_PRFIX "home/light/turn_left.png"),
    INIT_ICON(SIGNAL_LIGHT_AUTO_START_STOP, 96, 13,
              RES_PRFIX "home/light/auto_start_stop.png"),
    INIT_ICON(SIGNAL_LIGHT_TIRE, 167, 13, RES_PRFIX "home/light/tire.png"),
    INIT_ICON(SIGNAL_LIGHT_HIGH_BEAM, 237, 13,
              RES_PRFIX "home/light/high_beam.png"),
    INIT_ICON(SIGNAL_LIGHT_OIL_PRESSURE, 312, 13,
              RES_PRFIX "home/light/oil_pressure.png"),
    INIT_ICON(SIGNAL_LIGHT_ABS, 395, 13, RES_PRFIX "home/light/abs.png"),
    INIT_ICON(SIGNAL_LIGHT_ENGINE_FAULT, 469, 13,
              RES_PRFIX "home/light/engine_fault.png"),
    INIT_ICON(SIGNAL_LIGHT_WIFI, 542, 13, RES_PRFIX "home/light/wifi.png"),
    INIT_ICON(SIGNAL_LIGHT_BT_PAIR, 611, 13,
              RES_PRFIX "home/light/bt_pair.png"),
    INIT_ICON(SIGNAL_LIGHT_BT_ICON, 673, 12,
              RES_PRFIX "home/light/bt_icon.png"),
    INIT_ICON(SIGNAL_LIGHT_TURN_RIGHT, 739, 16,
              RES_PRFIX "home/light/turn_right.png"),
    INIT_ICON(SIGNAL_LIGHT_VOLTAGE, 28, 85, RES_PRFIX "home/light/voltage.png"),
};

void light_init() {
}
