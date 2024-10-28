/**
* @file light_view.h
*
* @brief This message displayed in Doxygen Files index
*
* @ingroup PackageName
* (note: this needs exactly one @defgroup somewhere)
*
* @date	2024-07-09-11-21
* @author Nemausa
*
*/
#ifndef LIGHT_VIEW_H_
#define LIGHT_VIEW_H_

#include "lvgl/lvgl.h"
#include "light.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum {
 kHide,
 kShow,
} DisplayTable;

typedef struct light_view {
  Icon icons[30];
  lv_obj_t *bg_;
  Light *light;
} LightView;

void LightViewInit(LightView *view);
void LightViewCreate(LightView *view);
void LightViewOne(lv_obj_t *bg, lv_obj_t **lv, image_pos pos);

#ifdef __cplusplus
}
#endif


#endif // LIGHT_VIEW_H_
