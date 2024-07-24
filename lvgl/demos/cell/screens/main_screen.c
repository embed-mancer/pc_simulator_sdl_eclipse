#include "main_screen.h"
#include "lvgl/lvgl.h"

#include "screen_interface.h"
#include "../cell.h"

lv_obj_t *main_scr = NULL;
LightView *light;
GearView *gear;

void main_screen_init() {
  main_scr = lv_obj_create(NULL);
  set_screen_color(main_scr, lv_color_black());
  lv_scr_load(main_scr);

  main_scrren_light();
  MainScreenGear();
}

void main_scrren_light() {
  light = malloc(sizeof(LightView));
  light->bg_ = main_scr;
  light->light = &light_main;
  LightViewInit(light);
  LightViewCreate(light);
}

void MainScreenGear() {
  gear = malloc(sizeof(GearView));
  gear->bg_ = main_scr;
  image_pos pos_key = {.image = "A:gear/n.png", .x = 84, .y = 155};
  image_pos pos_value = {.image = "A:gear/icon.png", .x = 84, .y = 253};
  gear->pos_key = pos_key;
  gear->pos_value = pos_value;
  GearViewInit(gear);
  GearViewCreate(gear);
}