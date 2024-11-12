#ifndef GUAGE_VIEW_H_
#define GUAGE_VIEW_H_

#include "../cell.h"

#define GUAGE_NUM 8

typedef enum {
  GUAGE_VIEW_MODE_BLOCK,
  GUAGE_VIEW_MODE_WIDTH,
} guage_view_mode_e;

typedef struct {
  lv_obj_t *icon;
  lv_obj_t *line;
  lv_obj_t *block[GUAGE_NUM];
  lv_obj_t *label[2];
  lv_obj_t *background;
  image_pos_t icon_position;
  image_pos_t line_position;
  image_pos_t block_position[GUAGE_NUM];
  label_pos_t label_position[2];
  guage_view_mode_e mode;
  int max_value;
} guage_view_t;

void guage_view_init(guage_view_t *view, guage_view_mode_e mode);
void guage_view_create(guage_view_t *view);
void guage_view_update(guage_view_t *view, int value);
void guage_view_toggle_day_night(guage_view_t *view);
void guage_view_main_oil(guage_view_t *view);
void guage_view_main_water(guage_view_t *view);

#endif  // GUAGE_VIEW_H_
