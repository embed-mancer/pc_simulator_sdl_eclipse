/**
* @file speed_view.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-07-24-10-53
* @author Nemausa
*
*/
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

  image_pos pos_unit;
  image_pos pos_block[3];
  char sz_block[10][32];
} SpeedView;

void SpeedViewInit(SpeedView *view);
void SpeedViewCreate(SpeedView *view);
void SpeedViewUpdate(SpeedView *view, int value);
void SpeedViewRun();
int SpeedViewCurrent();

#ifdef __cplusplus
}
#endif


#endif // SPEED_VIEW_H