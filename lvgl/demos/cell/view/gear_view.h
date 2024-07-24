/**
* @file gear_view.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-07-23-18-04
* @author Nemausa
*
*/
#ifndef GEAR_VIEW_H_
#define GEAR_VIEW_H_

#include "../light/light.h"
#include "../cell.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct gear_view {
  lv_obj_t *key;
  lv_obj_t *value;
  lv_obj_t *bg_;
  image_pos pos_key;
  image_pos pos_value;
} GearView;

void GearViewInit(GearView *view);
void GearViewCreate(GearView *view);
void GearViewUpdate(GearView *view, int value);

#ifdef __cplusplus
}
#endif


#endif // GEAR_VIEW_H_