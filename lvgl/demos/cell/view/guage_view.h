#ifndef GUAGE_VIEW_H_
#define GUAGE_VIEW_H_

#include "../cell.h"

#define kGuageNum 8

typedef enum {
  kGuageViewModeBlock,
  kGuageViewModeWidth,
} guage_view_mode;

typedef struct {
  lv_obj_t *icon_t;
  lv_obj_t *line;
  lv_obj_t *block[kGuageNum];
  lv_obj_t *label[2];
  lv_obj_t *background;
  image_pos_t icon_position;
  image_pos_t line_position;
  image_pos_t block_position[kGuageNum];
  label_pos_t label_position[2];
  guage_view_mode mode;
  int max_value;
} guage_view_t;

void guage_view_init(guage_view_t *view, guage_view_mode mode);
void guage_view_create(guage_view_t *view);
void guage_view_update(guage_view_t *view, int value);
void guage_view_toggle_day_night_mode(guage_view_t *view);
void guage_view_main_oil(guage_view_t *view);
void guage_view_main_water(guage_view_t *view);

#endif  // GUAGE_VIEW_H_
