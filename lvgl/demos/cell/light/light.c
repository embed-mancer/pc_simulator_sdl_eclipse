#include "light.h"

Light light_main = {
  .abs = {.x =96, .y = 12, .image = JUNRUI_LVGL_DIR"light/abs.png" },
  .turn_left = {.x = 9, .y = 9, .image = JUNRUI_LVGL_DIR"light/turn_left.png" },
  .turn_right = {.x = 743, .y = 9, .image = JUNRUI_LVGL_DIR"light/turn_right.png" },
  .high_beam = {.x = 171, .y = 13, .image = JUNRUI_LVGL_DIR"light/high_beam.png" },
  .engine_fault = {.x = 250, .y = 13, .image = JUNRUI_LVGL_DIR"light/engine_fault.png" },
  .location = {.x = 512, .y = 16, .image = JUNRUI_LVGL_DIR"light/location.png" },
  .maintain = {.x = 592, .y = 20, .image = JUNRUI_LVGL_DIR"light/maintain.png" },
  .voltage = {.x = 670, .y = 17, .image = JUNRUI_LVGL_DIR"light/voltage.png" },
};

void LightInit() {
}