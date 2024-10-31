#ifndef SPEED_VIEW_H
#define SPEED_VIEW_H

#include "../cell.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct speed_view {
  lv_obj_t *bg;
  lv_obj_t *unit;
  lv_obj_t *block[3];

  label_pos pos_unit;
  image_pos pos_block[3];
  char sz_block[10][32];
} SpeedView;

void SpeedViewInit(SpeedView *view);
void SpeedViewCreate(SpeedView *view);
void SpeedViewUpdate(SpeedView *view, int value);
void SpeedViewToggleDayNightMode(SpeedView *view);
void SpeedViewRun();
int SpeedViewCurrent();
void SpeedViewMain(SpeedView *view);

#ifdef __cplusplus
}
#endif


#endif // SPEED_VIEW_H
