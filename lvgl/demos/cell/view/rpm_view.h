#ifndef RPM_VIEW_H_
#define RPM_VIEW_H_

#include "../cell.h"

typedef struct rpm_view {
  lv_obj_t *line;
  lv_obj_t *num;
  lv_obj_t *unit;
  lv_obj_t *block[110];
  lv_obj_t *bg;
  image_pos pos_line;
  image_pos pos_num;
  image_pos pos_unit;
  image_pos pos_block[110];
} RpmView;

void RpmViewInit(RpmView *view);
void RpmViewCreate(RpmView *view);
void RpmViewUpdate(RpmView *view, int value);
void RpmViewRun();
int RpmViewCurrent();

#endif // RPM_VIEW_H_
