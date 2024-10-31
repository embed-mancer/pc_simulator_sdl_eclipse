#include "gear_view.h"

#include "../cell.h"
#include "../light/light_view.h"

void GearViewInit(GearView *view) {
  view->key = NULL;
  view->value = NULL;
  GearViewCreate(view);
}

void GearViewCreate(GearView *view) {
  CreateLabel(view->bg_, &view->key, view->key_position);
  CreateLabel(view->bg_, &view->value, view->value_position);
  lv_obj_set_style_text_align(view->key, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_align(view->value, LV_TEXT_ALIGN_CENTER, 0);
}

void GearViewUpdate(GearView *view, int value) {
  static char sz[4] = {0};
  snprintf(sz, sizeof(sz), "%d", value);

  if (strcmp(lv_label_get_text(view->value), sz) != 0) {
    lv_label_set_text(view->value, sz);
  }
}
