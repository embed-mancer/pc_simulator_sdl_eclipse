#include "mobile_window.h"
#include "window_manager.h"

static lv_obj_t *window  = NULL;
static lv_timer_t *timer = NULL;
static lv_obj_t *uuid    = NULL;
static lv_obj_t *status  = NULL;

static void task_cb(lv_timer_t *timer) {
}

static void create_qrcode() {
  lv_color_t bg_color = lv_palette_lighten(LV_PALETTE_LIGHT_BLUE, 5);
  lv_color_t fg_color = lv_palette_darken(LV_PALETTE_LIGHT_BLUE, 5);

  lv_obj_t *qr = lv_qrcode_create(window, 190, fg_color, bg_color);

  const char *data = "https://lvgl.io";
  lv_qrcode_update(qr, data, strlen(data));
  lv_obj_set_pos(qr, 560, 100);

  lv_obj_set_style_border_color(qr, bg_color, 0);
  lv_obj_set_style_border_width(qr, -5, 0);

  ui_helpers_create_label_left(window, &uuid, 70, 230, 500, 48,
                               tool_get_color_base(), LABEL_FONT_HARMONYOS_24,
                               "UUID:1990010010123456789");
}

void mobile_window_init() {
  window = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(window, lv_color_black(), 0);
  create_qrcode();
  timer = lv_timer_create(task_cb, 50, NULL);
  lv_timer_set_repeat_count(timer, LV_ANIM_REPEAT_INFINITE);
  window_manager_set_target(WINDOW_MOBILE);
}

void mobile_dindow_destroy() {
  lv_timer_del(timer);
  timer = NULL;
}

lv_obj_t *mobile_window_get() {
  return window;
}

void mobile_window_click(click_e click) {
  switch (click) {
  case CLICK_SHORT_SET:
    break;
  case CLICK_SHORT_BACK:
    window_manager_set_target(WINDOW_MENU);
    break;
  case CLICK_SHORT_UP:
    break;
  case CLICK_SHORT_DOWN:
    break;
  }
}
