/**
* @file oil_view.h
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
#ifndef OIL_VIEW_H_
#define OIL_VIEW_H_

#include "../cell.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct oil_view {
  lv_obj_t *icon;
  lv_obj_t *line;
  lv_obj_t *block[8];
  lv_obj_t *bg;
  image_pos pos_icon;
  image_pos pos_line;
  image_pos pos_block[8];
} OilView;

void OilViewInit(OilView *view);
void OilViewCreate(OilView *view);
void OilViewUpdate(OilView *view, int value);


#ifdef __cplusplus
}
#endif


#endif // OIL_VIEW_H_