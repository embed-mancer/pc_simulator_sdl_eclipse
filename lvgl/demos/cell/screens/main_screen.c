#include "main_screen.h"

#include "../cell.h"
#include "../light/light_control.h"
#include "lvgl/lvgl.h"
#include "screen_interface.h"
#include "../other/motor_model.h"
#include "../other/motor_controller.h"
#include "../view/blink_manager.h"

#define INIT_VIEW(view_ptr, type)                          \
  view_ptr = (type *)allocate_memory(sizeof(type), #type); \
  view_ptr->background = main_scr;

lv_obj_t *main_scr = NULL;
light_view_t *main_light;
gear_view_t *main_gear;
guage_view_t *main_oil;
guage_view_t *main_water;
rpm_view_t *main_rpm;
speed_view_t *main_speed;
other_view_t *main_other;
time_view_t *main_time;
blink_manager_t *main_blink;

static lv_obj_t *img_bg = NULL;

void *allocate_memory(size_t size, const char *type_name) {
  void *ptr = malloc(size);
  if (!ptr) {
    printf("Failed to allocate memory for %s\n", type_name);
    exit(EXIT_FAILURE);
  }
  return ptr;
}

void main_screen_task_cb(lv_timer_t *timer) {
  if (checkself_is_checking()) return;
  blink_manager_refresh(main_blink);
  // for test
  {
    static unsigned long last_switch_time = 0;
    static bool is_day_mode = true;
    unsigned long current_time = lv_tick_get();

    if (current_time - last_switch_time >= 5000) {
      last_switch_time = current_time;

      is_day_mode = !is_day_mode;
      if (is_day_mode)
        motor_model_set_day_night_mode(METER_MODE_NIGHT);
      else
        motor_model_set_day_night_mode(METER_MODE_DAY);
      main_screen_toggle_day_night();
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

static void set_screen_appearance(lv_obj_t *screen) {
  lv_color_t bg_color = (motor_model_get_day_night_mode() == METER_MODE_DAY)
                            ? lv_color_white()
                            : lv_color_black();
  set_screen_color(screen, bg_color);

  if (motor_model_get_day_night_mode() == METER_MODE_DAY) {
    CreateBackgroundImage(screen);
    lv_obj_clear_flag(img_bg, LV_OBJ_FLAG_HIDDEN);
  } else if (img_bg) {
    lv_obj_add_flag(img_bg, LV_OBJ_FLAG_HIDDEN);
  }
}

void main_screen_init() {
  main_scr = lv_obj_create(NULL);
  lv_scr_load(main_scr);
  set_screen_appearance(main_scr);
  tool_init();

  main_screen_blink();
  main_screen_signal_light();
  main_screen_oil();
  main_screen_water();
  main_screen_gear();
  main_screen_rpm();
  main_screen_other();
  main_screen_time();
  main_screen_speed();

  checkself_init();

  lv_timer_t *timer = lv_timer_create(main_screen_task_cb, 33, NULL);
  lv_timer_set_repeat_count(timer, LV_ANIM_REPEAT_INFINITE);
}

void main_screen_signal_light() {
  INIT_VIEW(main_light, light_view_t);
  main_light->light = &light_main;
  light_view_init(main_light);
}

void main_screen_gear() {
  INIT_VIEW(main_gear, gear_view_t);
  label_color_t color = tool_get_color_base();
  main_gear->key_position =
      create_label_pos(725, 397, 50, 20, color, LABEL_FONT_SOURCEHANSANSCN_18,
                       VALUE_TYPE_CHAR, (label_value_t){"GEAR"});
  main_gear->value_position = create_label_pos(
      738, 359, 20, 30, LABEL_COLOR_LIME_GREEN, LABEL_FONT_SOURCEHANSANSCN_34,
      VALUE_TYPE_CHAR, (label_value_t){"1"});
  gear_view_init(main_gear);
}

void main_screen_oil() {
  INIT_VIEW(main_oil, guage_view_t);
  guage_view_main_oil(main_oil);
}

void main_screen_water() {
  INIT_VIEW(main_water, guage_view_t);
  guage_view_main_water(main_water);
}

void main_screen_rpm() {
  INIT_VIEW(main_rpm, rpm_view_t);
  rpm_view_init(main_rpm);
}

void main_screen_speed() {
  INIT_VIEW(main_speed, speed_view_t);
  speed_view_main(main_speed);
}

void main_screen_other() {
  INIT_VIEW(main_other, other_view_t);
  other_view_init(main_other);
}

void main_screen_time() {
  INIT_VIEW(main_time, time_view_t);
  time_view_init(main_time);
}

void main_screen_blink() {
  main_blink = (blink_manager_t *)allocate_memory(sizeof(blink_manager_t),
                                                  "blink_manager_t");
  blink_manager_init(main_blink);
}

void main_screen_toggle_day_night() {
  set_screen_appearance(main_scr);
  guage_view_toggle_day_night_mode(main_oil);
  guage_view_toggle_day_night_mode(main_water);
  speed_view_toggle_day_night_mode(main_speed);
  rpm_view_toggle_day_night_mode(main_rpm);
  other_view_toggle_day_night_mode(main_other);
  gear_view_toggle_day_night_mode(main_gear);
  time_view_toggle_day_night_mode(main_time);
  speed_view_update(main_speed, speed_view_current());
}