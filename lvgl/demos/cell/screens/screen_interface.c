#include "screen_interface.h"


void set_screen_color(lv_obj_t *screen, lv_color_t value) {
  lv_obj_set_style_bg_color(screen, value, 0);
}