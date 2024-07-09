#include "light.h"

Light light_main = {
  .abs = {.x =96, .y = 12, .image = "A:light/abs.png" },
  .turn_left = {.x = 9, .y = 9, .image = "A:light/turn_left.png" },
  .turn_right = {.x = 743, .y = 9, .image = "A:light/turn_right.png" },
};

void LightInit() {
}