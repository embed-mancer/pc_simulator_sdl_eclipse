#include "screen_interface.h"

static PageTable page = kPageHome;

void ScreenInterfaceColor(lv_obj_t *bg, lv_color_t color) {
  lv_obj_set_style_bg_color(bg, color, 0);
}

PageTable ScreenInterfacePage() {
  return page;
}

void ScreenInterfaceSetPage(PageTable _page) {
  page = _page;
}
