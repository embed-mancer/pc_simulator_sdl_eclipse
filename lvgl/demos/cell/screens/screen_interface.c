#include "screen_interface.h"

void ScrrenInterfaceColor(lv_obj_t *bg, lv_color_t color) {
  lv_obj_set_style_bg_color(bg, color, 0);
}
