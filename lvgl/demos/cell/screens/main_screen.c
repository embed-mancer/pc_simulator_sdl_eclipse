#include "main_screen.h"

#include "../cell.h"
#include "../light/light_control.h"
#include "lvgl/lvgl.h"
#include "screen_interface.h"
#include "../other/motor_model.h"
#include "../other/motor_controller.h"
#include "../view/blink_manager.h"

lv_obj_t *main_scr = NULL;
LightView *main_light;
GearView *main_gear;
GuageView *main_oil;
GuageView *main_water;
RpmView *main_rpm;
SpeedView *main_speed;
OtherView *main_other;
TimeView *main_time;
BlinkManager *main_blink;

static lv_obj_t *img_bg = NULL;

void main_screen_task_cb(lv_timer_t *timer) {
  if (CheckSelfIsChecking()) return;
  BlinkManagerRefresh(main_blink);
  // for test
  {
    static unsigned long last_switch_time = 0;
    static bool is_day_mode = true;
    unsigned long current_time = lv_tick_get();

    if (current_time - last_switch_time >= 5000) {
      last_switch_time = current_time;

      is_day_mode = !is_day_mode;
      if (is_day_mode)
        MotorModelSetDayNightMode(kNightMode);
      else
        MotorModelSetDayNightMode(kDayMode);
      MainScreenToggleDayNight();
    }
  }
}

static void CreateBackgroundImage(lv_obj_t *screen) {
  if (!img_bg) {
    img_bg = lv_img_create(screen);
    lv_img_set_src(img_bg, RES_PRFIX "home/day/bg.png");
    lv_obj_set_pos(img_bg, 0, 0);
  }
}

static void SetScreenAppearance(lv_obj_t *screen) {
  lv_color_t bg_color = (MotorModelGetDayNightMode() == kDayMode)
                            ? lv_color_white()
                            : lv_color_black();
  set_screen_color(screen, bg_color);

  if (MotorModelGetDayNightMode() == kDayMode) {
    CreateBackgroundImage(screen);
    lv_obj_clear_flag(img_bg, LV_OBJ_FLAG_HIDDEN);
  } else if (img_bg) {
    lv_obj_add_flag(img_bg, LV_OBJ_FLAG_HIDDEN);
  }
}

void MainScreenInit() {
  main_scr = lv_obj_create(NULL);
  lv_scr_load(main_scr);
  SetScreenAppearance(main_scr);
  ToolInit();

  MainScreenBlink();
  MainScreenLight();
  MainScreenOil();
  MainScreenWater();
  MainScreenGear();
  MainScreenRpm();
  MainScreenOther();
  MainScreenTime();
  MainScreenSpeed();

  CheckSelfInit();

  lv_timer_t *timer = lv_timer_create(main_screen_task_cb, 33, NULL);
  lv_timer_set_repeat_count(timer, LV_ANIM_REPEAT_INFINITE);
}

void MainScreenLight() {
  main_light = malloc(sizeof(LightView));
  if (!main_light) return;
  main_light->bg_ = main_scr;
  main_light->light = &light_main;
  LightViewInit(main_light);
}

void MainScreenGear() {
  main_gear = malloc(sizeof(GearView));
  if (!main_gear) return;
  main_gear->background = main_scr;
  Color color = ToolGetColorBase();
  main_gear->key_position =
      CreateLabelPos(725, 397, 50, 20, color, kSourceHanSansCN_18, kTextChar,
                     (LabelValue){"GEAR"});
  main_gear->value_position =
      CreateLabelPos(738, 359, 20, 30, kColorLimeGreen, kSourceHanSansCN_34,
                     kTextChar, (LabelValue){"1"});
  GearViewInit(main_gear);
}

void MainScreenOil() {
  main_oil = malloc(sizeof(GuageView));
  if (!main_oil) return;
  main_oil->background = main_scr;
  GuageViewMainOil(main_oil);
}

void MainScreenWater() {
  main_water = malloc(sizeof(GuageView));
  if (!main_water) return;
  main_water->background = main_scr;
  GuageViewMainWater(main_water);
}

void MainScreenRpm() {
  main_rpm = malloc(sizeof(RpmView));
  if (!main_rpm) return;
  main_rpm->background = main_scr;
  RpmViewInit(main_rpm);
}

void MainScreenSpeed() {
  main_speed = malloc(sizeof(SpeedView));
  if (!main_speed) return;
  main_speed->background = main_scr;
  SpeedViewMain(main_speed);
}

void MainScreenOther() {
  main_other = malloc(sizeof(OtherView));
  if (!main_other) return;
  main_other->background = main_scr;
  OtherViewInit(main_other);
}

void MainScreenTime() {
  main_time = malloc(sizeof(TimeView));
  if (!main_time) return;
  main_time->background = main_scr;
  TimeViewInit(main_time);
}

void MainScreenToggleDayNight() {
  SetScreenAppearance(main_scr);
  GuageViewToggleDayNightMode(main_oil);
  GuageViewToggleDayNightMode(main_water);
  SpeedViewToggleDayNightMode(main_speed);
  RpmViewToggleDayNightMode(main_rpm);
  OtherViewToggleDayNightMode(main_other);
  GearViewToggleDayNightMode(main_gear);
  TimeViewToggleDayNightMode(main_time);
  SpeedViewUpdate(main_speed, SpeedViewCurrent());
}

void MainScreenBlink() {
  main_blink = malloc(sizeof(BlinkManager));
  if (!main_blink) return;
  BlinkManagerInit(main_blink);
}
