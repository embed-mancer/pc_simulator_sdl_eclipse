#include "gear_view.h"

#include "../cell.h"
#include "../light/light_view.h"
#include "../other/motor_model.h"

void gear_view_init(gear_view_t *view) {
  view->key = NULL;
  view->value = NULL;
  gear_view_create(view);
}

void gear_view_create(gear_view_t *view) {
  create_label(view->background, &view->key, view->key_position);
  create_label(view->background, &view->value, view->value_position);
  lv_obj_set_style_text_align(view->key, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_style_text_align(view->value, LV_TEXT_ALIGN_CENTER, 0);
}

void gear_view_update(gear_view_t *view, int value) {
  static char sz[4] = {0};
  snprintf(sz, sizeof(sz), "%d", value);

  if (strcmp(lv_label_get_text(view->value), sz) != 0) {
    lv_label_set_text(view->value, sz);
  }
}

void gear_view_toggle_day_night(gear_view_t *view) {
  tool_set_text_on_mode_and_update(view->key, &view->key_position.color,
                                   LABEL_COLOR_WHITE, LABEL_COLOR_BLACK);
  label_color_t value_color = (motor_model_get_day_night_mode() == METER_MODE_DAY)
                                  ? LABEL_COLOR_BLACK
                                  : LABEL_COLOR_LIME_GREEN;
  view->value_position.color = value_color;
  lv_obj_set_style_text_color(view->value, tool_get_color(value_color), 0);
}