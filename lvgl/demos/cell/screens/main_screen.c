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
  // MainScreenRpm();
  MainScreenOther();
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
  image_pos pos_icon = {.image = RES_PRFIX "rpm/icon.png", .x = 698, .y = 156};
  image_pos pos_line = {.image = RES_PRFIX "rpm/line.png", .x = 264, .y = 35};
  image_pos pos_block[24] = {
      [0] = {.image = RES_PRFIX "rpm/1.png", .x = 320, .y = 416},
      [1] = {.image = RES_PRFIX "rpm/2.png", .x = 312, .y = 391},
      [2] = {.image = RES_PRFIX "rpm/3.png", .x = 306, .y = 363},
      [3] = {.image = RES_PRFIX "rpm/4.png", .x = 304, .y = 337},
      [4] = {.image = RES_PRFIX "rpm/5.png", .x = 304, .y = 301},
      [5] = {.image = RES_PRFIX "rpm/6.png", .x = 305, .y = 278},
      [6] = {.image = RES_PRFIX "rpm/7.png", .x = 309, .y = 248},
      [7] = {.image = RES_PRFIX "rpm/8.png", .x = 317, .y = 223},
      [8] = {.image = RES_PRFIX "rpm/9.png", .x = 327, .y = 196},
      [9] = {.image = RES_PRFIX "rpm/10.png", .x = 341, .y = 172},
      [10] = {.image = RES_PRFIX "rpm/11.png", .x = 357, .y = 150},
      [11] = {.image = RES_PRFIX "rpm/12.png", .x = 377, .y = 131},
      [12] = {.image = RES_PRFIX "rpm/13.png", .x = 398, .y = 113},
      [13] = {.image = RES_PRFIX "rpm/14.png", .x = 423, .y = 99},
      [14] = {.image = RES_PRFIX "rpm/15.png", .x = 447, .y = 86},
      [15] = {.image = RES_PRFIX "rpm/16.png", .x = 475, .y = 79},
      [16] = {.image = RES_PRFIX "rpm/17.png", .x = 503, .y = 73},
      [17] = {.image = RES_PRFIX "rpm/18.png", .x = 534, .y = 72},
      [18] = {.image = RES_PRFIX "rpm/19.png", .x = 561, .y = 70},
      [19] = {.image = RES_PRFIX "rpm/20.png", .x = 590, .y = 72},
      [20] = {.image = RES_PRFIX "rpm/21.png", .x = 616, .y = 78},
      [21] = {.image = RES_PRFIX "rpm/22.png", .x = 643, .y = 86},
      [22] = {.image = RES_PRFIX "rpm/23.png", .x = 667, .y = 97},
      [23] = {.image = RES_PRFIX "rpm/24.png", .x = 691, .y = 112},
  };

  image_pos pos_num[7] = {
      [0] = {.image = RES_PRFIX "rpm/num_0.png", .x = 303, .y = 452},
      [1] = {.image = RES_PRFIX "rpm/num_2.png", .x = 276, .y = 328},
      [2] = {.image = RES_PRFIX "rpm/num_4.png", .x = 301, .y = 204},
      [3] = {.image = RES_PRFIX "rpm/num_6.png", .x = 377, .y = 105},
      [4] = {.image = RES_PRFIX "rpm/num_8.png", .x = 489, .y = 49},
      [5] = {.image = RES_PRFIX "rpm/num_10.png", .x = 612, .y = 49},
      [6] = {.image = RES_PRFIX "rpm/num_12.png", .x = 728, .y = 103},
  };
  main_rpm->pos_icon = pos_icon;
  main_rpm->pos_line = pos_line;
  for (int i = 0; i < 24; ++i) main_rpm->pos_block[i] = pos_block[i];
  for (int i = 0; i < 7; ++i) main_rpm->pos_num[i] = pos_num[i];

  RpmViewInit(main_rpm);
  RpmViewCreate(main_rpm);
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
