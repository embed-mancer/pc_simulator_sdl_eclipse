/**
* @file other_view.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-07-25-10-00
* @author Nemausa
*
*/
#ifndef OTHER_VIEW_H_
#define OTHER_VIEW_H_

#include "../cell.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct other_view {
  lv_obj_t *mode;
  lv_obj_t *beta_logo;
  lv_obj_t *odo_key;
  lv_obj_t *odo_value;
  lv_obj_t *odo_unit;
  lv_obj_t *trip_key;
  lv_obj_t *trip_value;
  lv_obj_t *trip_unit;
  lv_obj_t *avg_key;
  lv_obj_t *avg_value;
  lv_obj_t *avg_unit;

  lv_obj_t *bg;

  image_pos pos_mode;
  image_pos pos_beta;
  image_pos pos_odo_key;
  image_pos pos_odo_unit;
  image_pos pos_trip_key;
  image_pos pos_trip_unit;
  image_pos pos_avg_key;
  image_pos pos_avg_unit;
  lable_pos pos_odo_value;
  lable_pos pos_trip_value;
  lable_pos pos_avg_value;
} OtherView;

void OtherViewInit(OtherView *view);
void OtherViewCreate(OtherView *view);
void OtherViewUpdate(OtherView *view);
void OtherViewChangePos(lv_obj_t *value, lv_obj_t *unit, lable_pos pos);

#ifdef __cplusplus
}
#endif


#endif // OTHER_VIEW_H_