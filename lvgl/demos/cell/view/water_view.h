/**
* @file water_view.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-07-24-13-55
* @author Nemausa
*
*/
#ifndef WATER_VIEW_H_
#define WATER_VIEW_H_

#include "../cell.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
}
#endif

typedef struct water_view {
  lv_obj_t *icon;
  lv_obj_t *line;
  lv_obj_t *block[8];
  lv_obj_t *bg;
  image_pos pos_icon;
  image_pos pos_line;
  image_pos pos_block[8];
} WaterView;

void WaterViewInit(WaterView *view);
void WaterViewCreate(WaterView *view);
void WaterViewUpdate(WaterView *view, int value);

#endif // WATER_VIEW_H_