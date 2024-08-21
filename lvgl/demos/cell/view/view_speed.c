#include "view_speed.h"
#include "lvgl/src/core/lv_obj.h"
#include "lvgl/src/core/lv_obj_pos.h"
#include <lvgl/lvgl.h>

static void speed_changed_event_cb(lv_event_t * e);

static void set_angle(void * obj, int32_t v)
{
    lv_arc_set_value(obj, v);
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

static void speed_changed_event_cb(lv_event_t * e)
{
    lv_obj_t * arc = lv_event_get_target(e);
    lv_obj_t * label = lv_event_get_user_data(e);

    lv_label_set_text_fmt(label, "%d%%", lv_arc_get_value(arc));

    /*Rotate the label to the current position of the arc*/
    lv_arc_rotate_obj_to_angle(arc, label, 25);
}
