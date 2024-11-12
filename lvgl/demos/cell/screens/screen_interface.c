#include "screen_interface.h"

static window_e current_window = WINDOW_MENU;

void set_screen_color(lv_obj_t *screen, lv_color_t value) {
  lv_obj_set_style_bg_color(screen, value, 0);
}

window_e get_window() {
  return current_window;
}

void set_window(window_e window) {
  current_window = window;
}
