#include "view.h"
#include "lvgl/lvgl.h"

lv_obj_t *arc;
lv_obj_t *mask;
static lv_obj_t *window  = NULL;
static lv_obj_t *arc_img = NULL;

void create_bg(void) {
  window = lv_obj_create(NULL);
  lv_scr_load(window);

  arc_img = lv_img_create(window);
  lv_img_set_src(arc_img, "A:rpm_normal.png");
  lv_obj_set_pos(arc_img, 0, 0);

}

void view_main() {
  create_bg();
  create_arc_mask();
}
