#include "main_screen.h"

#include "../cell.h"
#include "../light/light_control.h"
#include "lvgl/lvgl.h"
#include "screen_interface.h"

lv_obj_t *main_scr = NULL;
LightView *light;
GearView *gear;
GuageView *main_oil;
GuageView *main_water;
RpmView *main_rpm;
SpeedView *main_speed;
OtherView *main_other;
TimeView *main_time;

void main_scrren_task_cb(lv_timer_t *timer) {
  if (CheckSelfIsChecking()) return;
  LightControlAll(light);
  NotifyOil(main_oil);
}

void main_screen_init() {
  main_scr = lv_obj_create(NULL);
  set_screen_color(main_scr, lv_color_black());
  lv_scr_load(main_scr);

  ToolInit();
  MainScreenLight();
  MainScreenOil();
  MainScreenWater();
  MainScreenGear();
  MainScreenRpm();
  MainScreenOther();
  MainScreenTime();
  MainScreenSpeed();
  CheckSelfInit();
  lv_timer_t *timer = lv_timer_create(main_scrren_task_cb, 33, NULL);
  lv_timer_set_repeat_count(timer, LV_ANIM_REPEAT_INFINITE);
}

void MainScreenLight() {
  light = malloc(sizeof(LightView));
  light->bg_ = main_scr;
  light->light = &light_main;
  LightViewInit(light);
}

void MainScreenGear() {
  gear = malloc(sizeof(GearView));
  gear->bg_ = main_scr;
  gear->key_position =
      CreateLabelPos(725, 397, 50, 20, kColorWhite, kSourceHanSansCN_18,
                     kTextChar, (LabelValue){"GEAR"});
  gear->value_position =
      CreateLabelPos(738, 359, 20, 30, kColorLimeGreen, kSourceHanSansCN_34,
                     kTextChar, (LabelValue){"1"});
  GearViewInit(gear);
}

void MainScreenOil() {
  main_oil = malloc(sizeof(GuageView));
  if (main_oil == NULL) {
    return;
  }
  main_oil->bg = main_scr;
  GuageViewMainOil(main_oil);
}

void MainScreenWater() {
  main_water = malloc(sizeof(GuageView));
  if (main_water == NULL) {
    return;
  }
  main_water->bg = main_scr;
  GuageViewMainWater(main_water);
}

void MainScreenRpm() {
  main_rpm = malloc(sizeof(RpmView));
  main_rpm->background = main_scr;
  RpmViewInit(main_rpm);
}

void MainScreenSpeed() {
  main_speed = malloc(sizeof(SpeedView));
  main_speed->background = main_scr;
  SpeedViewMain(main_speed);
}

void MainScreenOther() {
  main_other = malloc(sizeof(OtherView));
  main_other->bg = main_scr;
  OtherViewInit(main_other);
}

void MainScreenTime() {
  main_time = malloc(sizeof(TimeView));
  main_time->background = main_scr;
  TimeViewInit(main_time);
}
