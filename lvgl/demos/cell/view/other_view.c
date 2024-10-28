#include "other_view.h"

void OtherViewInit(OtherView *view) {
  view->mode = NULL;
  view->beta_logo = NULL;
  view->odo_key = NULL;
  view->odo_value = NULL;
  view->odo_unit = NULL;
  view->trip_key = NULL;
  view->trip_value = NULL;
  view->trip_unit = NULL;
  view->avg_key = NULL;
  view->avg_value = NULL;
  view->avg_unit = NULL;
}

void OtherViewCreate(OtherView *view) {
  LightViewOne(view->bg, &view->mode, view->pos_mode);
  LightViewOne(view->bg, &view->beta_logo, view->pos_beta);
  LightViewOne(view->bg, &view->odo_key, view->pos_odo_key);
  LightViewOne(view->bg, &view->odo_unit, view->pos_odo_unit);
  LightViewOne(view->bg, &view->trip_key, view->pos_trip_key);
  LightViewOne(view->bg, &view->trip_unit, view->pos_trip_unit);
  LightViewOne(view->bg, &view->avg_key, view->pos_avg_key);
  LightViewOne(view->bg, &view->avg_unit, view->pos_avg_unit);
  Label(view->bg, &view->odo_value, view->pos_odo_value);
  Label(view->bg, &view->trip_value, view->pos_trip_value);
  Label(view->bg, &view->avg_value, view->pos_avg_value);
}

void OtherViewUpdate(OtherView *view) {
  OtherViewChangePos(view->odo_value, view->odo_unit, view->pos_odo_value);
  OtherViewChangePos(view->trip_value, view->trip_unit, view->pos_trip_value);
  OtherViewChangePos(view->avg_value, view->avg_unit, view->pos_avg_value);
}

void OtherViewChangePos(lv_obj_t *value, lv_obj_t *unit, label_pos pos) {
  char* temp = lv_label_get_text(value);
  lv_point_t pos_temp;
  lv_coord_t letter_space = lv_obj_get_style_text_letter_space(value, LV_PART_MAIN);
  lv_coord_t width = lv_txt_get_width(temp, strlen(temp), 
                     ToolGetFont(pos.font), letter_space, LV_TEXT_FLAG_NONE);
  width = width + 10;
  lv_obj_set_pos(value, pos.x + 5, pos.y);
  lv_obj_set_width(value, width);

  lv_obj_set_x(unit, pos.x + width);
}
