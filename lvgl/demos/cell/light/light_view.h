#ifndef LIGHT_VIEW_H_
#define LIGHT_VIEW_H_

#include "lvgl/lvgl.h"
#include "light.h"

typedef enum {
  DISPLAY_STATE_HIDE,
  DISPLAY_STATE_SHOW,
} display_state_t;

typedef struct {
  icon_t icons[20];
  lv_obj_t *background;
  light *light;
} light_view_t;

void light_view_init(light_view_t *view);
void light_view_create(light_view_t *view);
void light_view_one(lv_obj_t *bg, lv_obj_t **lv, image_pos_t pos);
void light_view_display(icon_t *icon_t, display_state_t table);

#endif  // LIGHT_VIEW_H_
