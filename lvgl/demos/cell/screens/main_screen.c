#include "main_screen.h"
#include "lvgl/lvgl.h"

#include "screen_interface.h"
#include "../cell.h"

lv_obj_t *main_scr = NULL;
LightView *light;

void main_screen_init() {
  main_scr = lv_obj_create(NULL);
  set_screen_color(main_scr, lv_color_black());
  lv_scr_load(main_scr);

  main_scrren_light();
}

void main_scrren_light() {
  light = malloc(sizeof(LightView));
  light->bg_ = main_scr;
  light->light = &light_main;
  LightViewInit(light);
  LightViewCreate(light);
}