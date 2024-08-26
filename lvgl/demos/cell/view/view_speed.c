#include "view_speed.h"

static lv_obj_t *speed_value[2];

char *sz_block[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

static void set_angle(void * obj, int32_t v) {
  lv_arc_set_value(obj, v);
}

void ViewSpeedInit(SpeedView *view) {
  view->unit = NULL;
  view->block[0] = NULL;
  view->block[1] = NULL;
  view->block[2] = NULL;
}

void ViewSpeedCreate(SpeedView *view) {
  view->block[0] = lv_label_create(view->bg);
  view->block[1] = lv_label_create(view->bg);
  lv_obj_set_pos(view->block[0], 222, 100);
  lv_obj_set_pos(view->block[1], 222, 100);
  lv_label_set_text(view->block[0], "0");
  lv_obj_set_style_text_font(view->block[0], &AlternateGotNo2D_105, 0);
  lv_obj_set_style_text_font(view->block[1], &AlternateGotNo2D_105, 0);
  lv_obj_set_style_text_color(view->block[0], lv_color_black(), 0); 
  lv_obj_set_style_text_color(view->block[1], lv_color_black(), 0); 
  ViewSpeedUpdate(view, 0); 
}

void ViewSpeedUpdate(SpeedView *view,int value) {
  int mid = 240;
  int width = 36;
  if (value < 10) {
    lv_obj_set_x(view->block[0], mid-width/2);
    lv_obj_add_flag(view->block[1], LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text(view->block[0], sz_block[value]);
  } else if (value < 100){
    lv_obj_set_x(view->block[0], mid-width);
    lv_obj_set_x(view->block[1], mid);
    lv_obj_clear_flag(view->block[1], LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text(view->block[0], sz_block[value/10]);
    lv_label_set_text(view->block[1], sz_block[value%10]);
  }
}

void speed_arc(void) {
  /*Create an Arc*/
  lv_obj_t * arc = lv_arc_create(lv_scr_act());
  lv_arc_set_rotation(arc, 0);
  lv_arc_set_bg_angles(arc, 0, 180);

  lv_obj_remove_style(arc, NULL, LV_PART_KNOB);   /*Be sure the knob is not displayed*/
  lv_obj_center(arc);

  // Create a style and set the arc width
  static lv_style_t style;
  lv_style_init(&style);
  lv_style_set_arc_width(&style, 30);
  lv_obj_add_style(arc, &style, LV_PART_INDICATOR);
  lv_obj_add_style(arc, &style, LV_PART_MAIN);

  lv_anim_t a;
  lv_anim_init(&a);
  lv_anim_set_var(&a, arc);
  lv_anim_set_exec_cb(&a, set_angle);
  lv_anim_set_time(&a, 1000);
  lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);    /*Just for the demo*/
  lv_anim_set_repeat_delay(&a, 500);
  lv_anim_set_values(&a, 0, 100);
  lv_anim_start(&a);
}
