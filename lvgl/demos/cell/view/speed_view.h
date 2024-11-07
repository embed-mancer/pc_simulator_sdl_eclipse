#ifndef SPEED_VIEW_H
#define SPEED_VIEW_H

#include "../cell.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  lv_obj_t *background;
  lv_obj_t *unit;
  lv_obj_t *block[3];

  label_pos_t unit_position;
  image_pos_t block_position[3];
  char image_paths[10][MAX_IMAGE_CHARS ];
  int last_index;
} speed_view_t;

void speed_view_init(speed_view_t *view);
void speed_view_create(speed_view_t *view);
void speed_view_update(speed_view_t *view, int value);
void speed_view_toggle_day_night(speed_view_t *view);
void speed_view_run();
int speed_view_current();
void speed_view_main(speed_view_t *view);

#ifdef __cplusplus
}
#endif

#endif  // SPEED_VIEW_H
