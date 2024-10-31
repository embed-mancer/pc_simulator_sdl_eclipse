#ifndef LIGHT_VIEW_H_
#define LIGHT_VIEW_H_

#include "lvgl/lvgl.h"
#include "light.h"

typedef enum {
 kHide,
 kShow,
} DisplayTable;

typedef struct light_view {
  Icon icons[20];
  lv_obj_t *bg_;
  Light *light;
} LightView;

void LightViewInit(LightView *view);
void LightViewCreate(LightView *view);
void LightViewOne(lv_obj_t *bg, lv_obj_t **lv, ImagePos pos);
void LightViewDisplay(Icon *icon, DisplayTable table);


#endif // LIGHT_VIEW_H_
