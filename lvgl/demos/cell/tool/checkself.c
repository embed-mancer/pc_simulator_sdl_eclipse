#include "checkself.h"
#include "lvgl/lvgl.h"
#include "../light/light_control.h"
#include "constrant.h"

extern light_view_t *main_light;
extern gear_view_t *main_gear;
extern guage_view_t *main_oil;
extern guage_view_t *main_water;
extern rpm_view_t *main_rpm;
extern speed_view_t *main_speed;
extern other_view_t *main_other;

typedef struct {
  int check_time;
  int oil_divisor;
  int water_divisor;
  float rpm_divisor;
  float speed_divisor;
} check_config_t;

static check_config_t config = {3000, 18, 18, 25.0, 450.0};

typedef enum {
  CHECK_STATE_IDLE,
  CHECK_STATE_WAITING,
  CHECK_STATE_CHECKING,
  CHECK_STATE_FINISHED
} check_state_t;

typedef struct {
  lv_timer_t *timer;
  check_state_t state;
  uint32_t start_tick;
  float speed_factor;
  float rpm_factor;
  int water_factor;
  int oil_factor;
  bool is_checking;
  int check_count;
} checkself_manager_t;

static checkself_manager_t manager = {
    NULL, CHECK_STATE_IDLE, 0, 0, 0, 0, 0, false, 0};

void checkself_update_views(int oil_value, int water_value, int rpm_value,
                            int speed_value) {
  guage_view_update(main_oil, oil_value);
  guage_view_update(main_water, water_value);
  rpm_view_update(main_rpm, rpm_value);
  speed_view_update(main_speed, speed_value);
}

void check_state_idle() {
  // TODO
}

void check_state_waiting() {
  if (lv_tick_elaps(manager.start_tick) > 3000) {
    manager.state = CHECK_STATE_CHECKING;
    manager.start_tick = lv_tick_get();
  }
}

void check_state_checking() {
  const int max_check_count = 60;
  const int half_check_count = 30;

  manager.is_checking = true;
  manager.check_count++;

  if (manager.check_count > max_check_count) {
    manager.state = CHECK_STATE_FINISHED;
    return;
  }

  int count = (manager.check_count > half_check_count)
                  ? (max_check_count - manager.check_count)
                  : manager.check_count;

  int oil_value = count / 3;
  int water_value = count / 3;
  int rpm_value = count * 400;
  int speed_value = count * 7.3;

  ligth_control_check(main_light);
  checkself_update_views(oil_value, water_value, rpm_value, speed_value);
}

void check_state_finished() { checkself_finish(); }

void CheckSelfTask(lv_timer_t *timer) {
  switch (manager.state) {
    case CHECK_STATE_IDLE:
      check_state_idle();
      break;
    case CHECK_STATE_WAITING:
      check_state_waiting();
      break;
    case CHECK_STATE_CHECKING:
      check_state_checking();
      break;
    case CHECK_STATE_FINISHED:
      check_state_finished();
      break;
    default:
      break;
  }
}

void checkself_init() {
  manager.oil_factor = config.check_time / config.oil_divisor + 1;
  manager.water_factor = config.check_time / config.water_divisor + 1;
  manager.rpm_factor = config.check_time / config.rpm_divisor + 1;
  manager.speed_factor = config.check_time / config.speed_divisor;

  manager.timer = lv_timer_create(CheckSelfTask, 33, NULL);
  lv_timer_set_repeat_count(manager.timer, LV_ANIM_REPEAT_INFINITE);

  manager.state = CHECK_STATE_WAITING;
  manager.start_tick = lv_tick_get();
}

void checkself_finish() {
  if (manager.timer) {
    lv_timer_del(manager.timer);
    manager.timer = NULL;
  }
  manager.is_checking = false;
  manager.state = CHECK_STATE_IDLE;
  checkself_update_views(0, 0, 0, 0);
}

bool checkself_is_checking() { return manager.is_checking; }

void checkself_set_checking(bool is_checking) {
  manager.is_checking = is_checking;
}