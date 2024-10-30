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
  gear->pos_key =
      CreateLabelPos(725, 397, 50, 20, kColorWhite, kSourceHanSansCN_18,
                     kTextChar, (LabelValue){"GEAR"});
  gear->pos_value =
      CreateLabelPos(738, 359, 20, 30, kColorLimeGreen, kSourceHanSansCN_34,
                     kTextChar, (LabelValue){"1"});
  GearViewInit(gear);
}

void MainScreenOil() {
  main_oil = malloc(sizeof(GuageView));
  main_oil->bg = main_scr;
  main_oil->pos_icon =
      CreateImagePos(RES_PRFIX "home/night/oil_normal.png", 30, 430);
  main_oil->pos_line =
      CreateImagePos(RES_PRFIX "home/night/oil_line.png", 91, 444);
  main_oil->pos_block[0] =
      CreateImagePos(RES_PRFIX "home/night/oil_width.png", 92, 444);
  main_oil->pos_label[0] =
      CreateLabelPos(75, 440, 10, 20, kColorRed, kSourceHanSansCN_18, kTextChar,
                     (LabelValue){"E"});
  main_oil->pos_label[1] =
      CreateLabelPos(298, 440, 10, 20, kColorWhite, kSourceHanSansCN_18,
                     kTextChar, (LabelValue){"F"});
  GuageViewInit(main_oil, kGuageViewModeWidth);
}

void MainScreenWater() {
  main_water = malloc(sizeof(GuageView));
  main_water->bg = main_scr;
  main_water->pos_icon =
      CreateImagePos(RES_PRFIX "home/night/water_normal.png", 487, 430);
  main_water->pos_line =
      CreateImagePos(RES_PRFIX "home/night/water_line.png", 554, 444);
  main_water->pos_block[0] =
      CreateImagePos(RES_PRFIX "home/night/water_width.png", 554, 444);
  main_water->pos_label[0] =
      CreateLabelPos(764, 441, 10, 20, kColorRed, kSourceHanSansCN_18,
                     kTextChar, (LabelValue){"H"});
  main_water->pos_label[1] =
      CreateLabelPos(531, 441, 10, 20, kColorWhite, kSourceHanSansCN_18,
                     kTextChar, (LabelValue){"C"});
  GuageViewInit(main_water, kGuageViewModeWidth);
}

void MainScreenRpm() {
  main_rpm = malloc(sizeof(RpmView));
  main_rpm->bg = main_scr;
  RpmViewInit(main_rpm);
}

void MainScreenSpeed() {
  main_speed = malloc(sizeof(SpeedView));
  main_speed->bg = main_scr;
  for (int i = 0; i < 10; ++i) {
    snprintf(main_speed->sz_block[i], sizeof(main_speed->sz_block[i]),
             RES_PRFIX "home/night/speed/%d.png", i);
  }
  main_speed->pos_block[0] = CreateImagePos(main_speed->sz_block[0], 320, 258);
  main_speed->pos_block[1] = CreateImagePos(main_speed->sz_block[0], 320, 258);
  main_speed->pos_block[2] = CreateImagePos(main_speed->sz_block[0], 320, 258);
  main_speed->pos_unit =
      CreateLabelPos(507, 334, 55, 30, 
                     kColorWhite, kSourceHanSansCN_22,
                     kTextChar, (LabelValue){"km/h"});
  SpeedViewInit(main_speed);
}

void MainScreenOther() {
  main_other = malloc(sizeof(OtherView));
  main_other->bg = main_scr;
  OtherViewInit(main_other);
}

void MainScreenTime() {
  main_time = malloc(sizeof(TimeView));
  main_time->bg = main_scr;
  TimeViewInit(main_time);
}
