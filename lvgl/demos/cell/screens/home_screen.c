#include "home_screen.h"
#include "menu_screen.h"
#include "screen_interface.h"
#include "../view/view_speed.h"
#include "../view/view_other.h"

lv_obj_t *home_screen = NULL;
SpeedView *home_speed = NULL;

void HomeScreenTask(lv_timer_t *timer) {
}

void HomeScreenInit() {
  MenuScreenInit();
  return;
  home_screen = lv_obj_create(NULL);
  ScrrenInterfaceColor(home_screen, lv_color_white());
  lv_scr_load(home_screen);

  HomeScreenSpeed();
  HomeScreenOther();

  lv_timer_t *timer = lv_timer_create(HomeScreenTask, 33, NULL);
  lv_timer_set_repeat_count(timer, LV_ANIM_REPEAT_INFINITE);
}

void HomeScreenSpeed() {
  home_speed = malloc(sizeof(SpeedView));
  home_speed->bg = home_screen;
  ViewSpeedInit(home_speed);
  ViewSpeedCreate(home_speed);
}

void HomeScreenOther() {
  ViewOtherCreate();
}
