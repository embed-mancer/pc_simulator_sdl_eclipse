#ifndef RPM_VIEW_H_
#define RPM_VIEW_H_

#include "../cell.h"

typedef struct rpm_view {
  lv_obj_t *line;
  lv_obj_t *num;
  lv_obj_t *unit;
  lv_obj_t *block;
  lv_obj_t *background;
  ImagePos line_position;
  ImagePos number_position;
  ImagePos unit_position;
  ImagePos block_positions[110];
} RpmView;

void RpmViewInit(RpmView *view);
void RpmViewCreate(RpmView *view);
void RpmViewUpdate(RpmView *view, int value);
void RpmViewToggleDayNightMode(RpmView *view);
void RpmViewRun();
int RpmViewCurrent();

#endif  // RPM_VIEW_H_
