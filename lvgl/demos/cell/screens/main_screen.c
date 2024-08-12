#include "main_screen.h"
#include "lvgl/lvgl.h"

#include "screen_interface.h"
#include "../cell.h"
#include "../light/light_controller.h"

lv_obj_t *main_scr = NULL;
LightView *light;
GearView *gear;
OilView *main_oil;
WaterView *main_water;
RpmView *main_rpm;
SpeedView *main_speed;
OtherView *main_other;

void main_scrren_task_cb(lv_timer_t *timer) {
  // LightNotifyAll(light);
  // SpeedViewRun();
  // RpmViewRun();
}

void main_screen_init() {
  main_scr = lv_obj_create(NULL);
  set_screen_color(main_scr, lv_color_black());
  lv_scr_load(main_scr);

  MainScreenLight();
  MainScreenGear();
  MainScreenOil();
  MainScreenWater();
  MainScreenRpm();
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

void MainScreenOil() {
  main_oil = malloc(sizeof(OilView));
  main_oil->bg = main_scr;
  image_pos pos_icon = {.image = "A:oil/icon.png", .x = 380, .y = 441};
  image_pos pos_line = {.image = "A:oil/line.png", .x = 343, .y = 234};
  image_pos pos_block[8] = {
    [0] = {.image = "A:oil/1.png", .x = 361, .y = 401},
    [1] = {.image = "A:oil/2.png", .x = 353, .y = 376},
    [2] = {.image = "A:oil/3.png", .x = 349, .y = 353},
    [3] = {.image = "A:oil/4.png", .x = 348, .y = 335},
    [4] = {.image = "A:oil/5.png", .x = 347, .y = 309},
    [5] = {.image = "A:oil/6.png", .x = 348, .y = 273},
    [6] = {.image = "A:oil/7.png", .x = 351, .y = 258},
    [7] = {.image = "A:oil/8.png", .x = 358, .y = 238},
  };
  main_oil->pos_icon = pos_icon;
  main_oil->pos_line = pos_line;
  for (int i = 0; i < 8; ++i)
    main_oil->pos_block[i] = pos_block[i];
  OilViewInit(main_oil);
  OilViewCreate(main_oil);
}

void MainScreenWater() {
  main_water = malloc(sizeof(WaterView));
  main_water->bg = main_scr;
  image_pos pos_icon = {.image = "A:water/icon.png", .x = 418, .y = 416};
  image_pos pos_line = {.image = "A:water/line.png", .x = 384, .y = 251};
  image_pos pos_block[8] = {
    [0] = {.image = "A:water/1.png", .x = 399, .y = 388},
    [1] = {.image = "A:water/2.png", .x = 390, .y = 364},
    [2] = {.image = "A:water/3.png", .x = 389, .y = 353},
    [3] = {.image = "A:water/4.png", .x = 388, .y = 335},
    [4] = {.image = "A:water/5.png", .x = 388, .y = 314},
    [5] = {.image = "A:water/6.png", .x = 388, .y = 291},
    [6] = {.image = "A:water/7.png", .x = 388, .y = 260},
    [7] = {.image = "A:water/8.png", .x = 392, .y = 256},
  };
  main_water->pos_icon = pos_icon;
  main_water->pos_line = pos_line;
  for (int i = 0; i < 8; ++i)
    main_water->pos_block[i] = pos_block[i];
  WaterViewInit(main_water);
  WaterViewCreate(main_water);
}

void MainScreenRpm() {
  main_rpm = malloc(sizeof(RpmView));
  main_rpm->bg = main_scr;
  image_pos pos_icon = {.image = "A:rpm/icon.png", .x = 698, .y = 156};
  image_pos pos_line = {.image = "A:rpm/line.png", .x = 264, .y = 35};
  image_pos pos_block[24] = {
    [0] = {.image = "A:rpm/1.png", .x = 320, .y = 416},
    [1] = {.image = "A:rpm/2.png", .x = 312, .y = 391},
    [2] = {.image = "A:rpm/3.png", .x = 306, .y = 363},
    [3] = {.image = "A:rpm/4.png", .x = 304, .y = 337},
    [4] = {.image = "A:rpm/5.png", .x = 304, .y = 301},
    [5] = {.image = "A:rpm/6.png", .x = 305, .y = 278},
    [6] = {.image = "A:rpm/7.png", .x = 309, .y = 248},
    [7] = {.image = "A:rpm/8.png", .x = 317, .y = 223},
    [8] = {.image = "A:rpm/9.png", .x = 327, .y = 196},
    [9] = {.image = "A:rpm/10.png", .x = 341, .y = 172},
    [10] = {.image = "A:rpm/11.png", .x = 357, .y = 150},
    [11] = {.image = "A:rpm/12.png", .x = 377, .y = 131},
    [12] = {.image = "A:rpm/13.png", .x = 398, .y = 113},
    [13] = {.image = "A:rpm/14.png", .x = 423, .y = 99},
    [14] = {.image = "A:rpm/15.png", .x = 447, .y = 86},
    [15] = {.image = "A:rpm/16.png", .x = 475, .y = 79},
    [16] = {.image = "A:rpm/17.png", .x = 503, .y = 73},
    [17] = {.image = "A:rpm/18.png", .x = 534, .y = 72},
    [18] = {.image = "A:rpm/19.png", .x = 561, .y = 70},
    [19] = {.image = "A:rpm/20.png", .x = 590, .y = 72},
    [20] = {.image = "A:rpm/21.png", .x = 616, .y = 78},
    [21] = {.image = "A:rpm/22.png", .x = 643, .y = 86},
    [22] = {.image = "A:rpm/23.png", .x = 667, .y = 97},
    [23] = {.image = "A:rpm/24.png", .x = 691, .y = 112},
  };

  image_pos pos_num[7] = {
    [0] = {.image = "A:rpm/num_0.png", .x = 303, .y = 452},
    [1] = {.image = "A:rpm/num_2.png", .x = 276, .y = 328},
    [2] = {.image = "A:rpm/num_4.png", .x = 301, .y = 204},
    [3] = {.image = "A:rpm/num_6.png", .x = 377, .y = 105},
    [4] = {.image = "A:rpm/num_8.png", .x = 489, .y = 49},
    [5] = {.image = "A:rpm/num_10.png", .x = 612, .y = 49},
    [6] = {.image = "A:rpm/num_12.png", .x = 728, .y = 103},
  };
  main_rpm->pos_icon = pos_icon;
  main_rpm->pos_line = pos_line;
  for (int i = 0; i < 24; ++i)
    main_rpm->pos_block[i] = pos_block[i];
  for (int i = 0; i < 7; ++i)
    main_rpm->pos_num[i] = pos_num[i];

  RpmViewInit(main_rpm);
  RpmViewCreate(main_rpm);
}

void MainScreenSpeed() {
  main_speed = malloc(sizeof(SpeedView));
  main_speed->bg = main_scr;
  image_pos pos_unit = {.image = "A:speed/km.png", .x = 726, .y = 346};
  image_pos pos_block[3] = {
    [0] = {.image = "A:speed/0.png", .x = 320, .y = 212},
    [1] = {.image = "A:speed/0.png", .x = 312, .y = 212},
    [2] = {.image = "A:speed/0.png", .x = 306, .y = 212},
  };
  strcpy(main_speed->sz_block[0], "A:speed/0.png");
  strcpy(main_speed->sz_block[1], "A:speed/1.png");
  strcpy(main_speed->sz_block[2], "A:speed/2.png");
  strcpy(main_speed->sz_block[3], "A:speed/3.png");
  strcpy(main_speed->sz_block[4], "A:speed/4.png");
  strcpy(main_speed->sz_block[5], "A:speed/5.png");
  strcpy(main_speed->sz_block[6], "A:speed/6.png");
  strcpy(main_speed->sz_block[7], "A:speed/7.png");
  strcpy(main_speed->sz_block[8], "A:speed/8.png");
  strcpy(main_speed->sz_block[9], "A:speed/9.png");
  main_speed->pos_block[0] = pos_block[0];
  main_speed->pos_block[1] = pos_block[1];
  main_speed->pos_block[2] = pos_block[2];
  main_speed->pos_unit = pos_unit;
  SpeedViewInit(main_speed);
  SpeedViewCreate(main_speed);
}

void MainScreenOther() {
  main_other = malloc(sizeof(OtherView));
  main_other->bg = main_scr;
  image_pos pos_mode = {.image = "A:other/mode.png", .x = 17, .y = 434};
  image_pos pos_beta = {.image = "A:other/beta.png", .x = 506, .y = 129};
  image_pos pos_odo_key = {.image = "A:other/odo_key.png", .x = 539, .y = 376};
  lable_pos pos_odo_value = {.x = 602, .y = 376, .w = 110, .h = 20,
                             .color = kColorWhite, .font = kPlagiata_27,
                             .value_type = 2, .text.i = 999999};
  image_pos pos_odo_unit = {.image = "A:other/odo_unit.png", .x = 715, .y = 376};

  image_pos pos_trip_key = {.image = "A:other/trip_key.png", .x = 545, .y = 404};
  lable_pos pos_trip_value = {.x = 609, .y = 404, .w = 80, .h = 20,
                             .color = kColorWhite, .font = kPlagiata_27,
                             .value_type = 1, .text.f = 1.0};
  image_pos pos_trip_unit = {.image = "A:other/trip_unit.png", .x = 693, .y = 404};

  image_pos pos_avg_key = {.image = "A:other/avg_key.png", .x = 524, .y = 436};
  lable_pos pos_avg_value = {.x = 620, .y = 435, .w = 50, .h = 20,
                             .color = kColorWhite, .font = kPlagiata_37,
                             .value_type = 2, .text.i = 0};
  image_pos pos_avg_unit = {.image = "A:other/avg_unit.png", .x = 681, .y = 436};

  main_other->pos_mode = pos_mode;
  main_other->pos_beta = pos_beta;
  main_other->pos_odo_key = pos_odo_key;
  main_other->pos_odo_value = pos_odo_value;
  main_other->pos_odo_unit = pos_odo_unit;

  main_other->pos_trip_key = pos_trip_key;
  main_other->pos_trip_value = pos_trip_value;
  main_other->pos_trip_unit = pos_trip_unit;

  main_other->pos_avg_key = pos_avg_key;
  main_other->pos_avg_value = pos_avg_value;
  main_other->pos_avg_unit = pos_avg_unit;

  OtherViewInit(main_other);
  OtherViewCreate(main_other);
  OtherViewUpdate(main_other);
}
