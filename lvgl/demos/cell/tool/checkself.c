#include "checkself.h"
#include "lvgl/lvgl.h"
#include "../light/light_control.h"
#include "constrant.h"

extern LightView *light;
extern GearView *gear;
extern GuageView *main_oil;
extern GuageView *main_water;
extern RpmView *main_rpm;
extern SpeedView *main_speed;
extern OtherView *main_other;

typedef struct {
  int check_time;
  int oil_divisor;
  int water_divisor;
  float rpm_divisor;
  float speed_divisor;
} CheckConfig;

static CheckConfig config = {3000, 18, 18, 25.0, 450.0};

typedef enum {
  kStateIdle,
  kStateWaiting,
  kStateChecking,
  kStateFinished
} CheckState;

typedef struct {
  lv_timer_t *timer;
  CheckState state;
  uint32_t start_tick;
  float speed_factor;
  float rpm_factor;
  int water_factor;
  int oil_factor;
  bool is_checking;
} CheckSelfManager;

static CheckSelfManager manager = {NULL, kStateIdle, 0, 0, 0, 0, 0, false};

void CheckSelfUpdateViews(int oil_value, int water_value, int rpm_value,
                          int speed_value) {
  GuageViewUpdate(main_oil, oil_value);
  GuageViewUpdate(main_water, water_value);
  // RpmViewUpdate(main_rpm, rpm_value);
  SpeedViewUpdate(main_speed, speed_value);
}

void CheckStateIdle() {
}

void CheckStateWaiting() {
  if (lv_tick_elaps(manager.start_tick) > 3000) {
    manager.state = kStateChecking;
    manager.start_tick = lv_tick_get();
  }
}

void CheckStateChecking() {
  manager.is_checking = true;
  uint32_t check_elapsed = lv_tick_elaps(manager.start_tick);
  if (check_elapsed >= kCheckTime) {
    manager.state = kStateFinished;
    return;
  }

  uint32_t half_check = kCheckTime / 2;
  uint32_t progress_time =
      check_elapsed < half_check ? check_elapsed : (kCheckTime - check_elapsed);

  int oil_value = progress_time / manager.oil_factor;
  int water_value = progress_time / manager.water_factor;
  int rpm_value = (progress_time / manager.rpm_factor) * 1000;
  int speed_value = progress_time / manager.speed_factor;

  LightControlCheck(light);
  CheckSelfUpdateViews(oil_value, water_value, rpm_value, speed_value);
}

void CheckStateFinished() {
  CheckSelfFinish();
}

void CheckSelfTask(lv_timer_t *timer) {
  switch (manager.state) {
    case kStateIdle:
      CheckStateIdle();
      break;
    case kStateWaiting:
      CheckStateWaiting();
      break;
    case kStateChecking:
      CheckStateChecking();
      break;
    case kStateFinished:
      CheckStateFinished();
      break;
    default:
      break;
  }
}

void CheckSelfInit() {
  manager.oil_factor = config.check_time / config.oil_divisor + 1;
  manager.water_factor = config.check_time / config.water_divisor + 1;
  manager.rpm_factor = config.check_time / config.rpm_divisor + 1;
  manager.speed_factor = config.check_time / config.speed_divisor;

  manager.timer = lv_timer_create(CheckSelfTask, 33, NULL);
  lv_timer_set_repeat_count(manager.timer, LV_ANIM_REPEAT_INFINITE);

  manager.state = kStateWaiting;
  manager.start_tick = lv_tick_get();
}

void CheckSelfFinish() {
  if (manager.timer) {
    lv_timer_del(manager.timer);
    manager.timer = NULL;
  }
  manager.is_checking = false;
  manager.state = kStateIdle;
  CheckSelfUpdateViews(0, 0, 0, 0);
}

bool CheckSelfIsChecking() {
  return manager.is_checking;
}

void CheckSelfChecking(bool is_checking) {
  manager.is_checking = is_checking;
}
