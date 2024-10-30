#ifndef RPM_VIEW_H_
#define RPM_VIEW_H_

#include "../cell.h"

typedef struct rpm_view {
  lv_obj_t *icon;
  lv_obj_t *line;
  lv_obj_t *block[24];
  lv_obj_t *num[7];
  lv_obj_t *bg;
  image_pos pos_icon;
  image_pos pos_line;
  image_pos pos_block[24];
  image_pos pos_num[7];
} RpmView;

void RpmViewInit(RpmView *view);
void RpmViewCreate(RpmView *view);
void RpmViewUpdate(RpmView *view, int value);
void RpmViewRun();
int RpmViewCurrent();

#endif // RPM_VIEW_H_
