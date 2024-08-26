/**
* @file view_speed.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-08-21-11-43
* @author Nemausa
*
*/
#ifndef VIEW_SPEED_H_
#define VIEW_SPEED_H_

#include "../cell.h"

typedef struct speed_view {
  lv_obj_t *bg;
  lv_obj_t *unit;
  lv_obj_t *block[3];
} SpeedView;

void speed_arc();
void ViewSpeedInit(SpeedView*);
void ViewSpeedUpdate(SpeedView *,int value);
void ViewSpeedCreate(SpeedView*);

#endif // VIEW_SPEED_H_
