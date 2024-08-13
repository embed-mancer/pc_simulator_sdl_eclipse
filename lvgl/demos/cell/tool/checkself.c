#include "checkself.h"
#include "lvgl/lvgl.h"
#include "../light/light_controller.h"
#include "constrant.h"

extern LightView *light;
extern GearView *gear;
extern OilView *main_oil;
extern WaterView *main_water;
extern RpmView *main_rpm;
extern SpeedView *main_speed;
extern OtherView *main_other;

lv_timer_t *check_timer = NULL;;

float speed;
float rpm;
int water;
int oil;

int anim_tick = 0;
bool anim_update = true;
int begin_tick = 0;
bool begin_update = true;

bool is_checking_ = false;

void CheckSelfTask(lv_timer_t *timer) {
  if (lv_tick_get() > 3000) {
    if (anim_update) {
      anim_update = false;
      anim_tick = lv_tick_get();
    }
  }

  if (!anim_update) {
    if (lv_tick_elaps(anim_tick) > 500) {
      if (begin_update) {
        begin_tick = lv_tick_get();
        begin_update = false;
        anim_update = true;
        is_checking_ = true;
      }
    }
  }

  if (!begin_update) {
    uint32_t temp = lv_tick_elaps(begin_tick);
    if (temp > kCheckTime) {
      CheckSelfFinish();
      return;
    }
    uint32_t time = temp < (kCheckTime / 2) ? temp : (kCheckTime - temp);
    int oil_value = time / oil;
    int water_value = time / water;
    int rmp_value = time / rpm * 1000;
    int speed_value = time / speed;
    LightCheck(light);
    OilViewUpdate(main_oil, oil_value);
    WaterViewUpdate(main_water, water_value);
    RpmViewUpdate(main_rpm, rmp_value);
    SpeedViewUpdate(main_speed, speed_value);
  }

}

void CheckSelfInit() {
  oil = kCheckTime / 2 / 9 + 1;
  water = kCheckTime / 2 / 9 + 1;
  rpm = kCheckTime / 2/ 13.0 + 1;
  speed = kCheckTime / 2 / 200.0;
  const int period = 33;
  check_timer = lv_timer_create(CheckSelfTask, period, NULL);
  lv_timer_set_repeat_count(check_timer, LV_ANIM_REPEAT_INFINITE);
}

void CheckSelfFinish() {
  if (check_timer) {
    OilViewUpdate(main_oil, 0);
    WaterViewUpdate(main_water, 0);
    RpmViewUpdate(main_rpm, 0);
    SpeedViewUpdate(main_speed, 0);
    is_checking_ = false;
    lv_timer_del(check_timer);
  }
}

bool CheckSelfIsChecking() {
  return is_checking_;
}

void CheckSelfChecking(bool is_checking) {
  is_checking_ = is_checking;
}