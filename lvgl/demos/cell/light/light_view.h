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
void LightViewDisplay(Icon *icon, DisplayTable table);

#ifdef __cplusplus
}
#endif


#endif // LIGHT_VIEW_H_
