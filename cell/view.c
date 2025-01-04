#include "view.h"
#include "lvgl/lvgl.h"

lv_obj_t *arc;
lv_obj_t *mask;
static lv_obj_t *window  = NULL;
static lv_obj_t *arc_img = NULL;
int16_t mask_id          = 0;

void create_arc_on_canvas(lv_obj_t *parent) {
  // 创建画布
  lv_obj_t *canvas = lv_canvas_create(parent);
  lv_obj_set_size(canvas, 240, 240);  // 设置画布的大小
  lv_obj_set_pos(canvas, 0, 0);       // 设置画布的位置

  // 定义弧线的参数
  lv_coord_t x         = 120;                        // 弧线的中心 X 坐标
  lv_coord_t y         = 120;                        // 弧线的中心 Y 坐标
  lv_coord_t radius    = 10;                         // 半径
  uint16_t start_angle = 0;                          // 起始角度
  uint16_t end_angle   = 45;                         // 结束角度
  lv_color_t color     = lv_color_make(0xFF, 0xFF, 0xFF);  // 弧线的颜色

  lv_draw_arc_dsc_t draw_src;
  lv_draw_arc_dsc_init(&draw_src);
  // draw_src.img_src = arc_img;
  draw_src.color       = color;
  draw_src.width       = radius;
  draw_src.start_angle = start_angle;
  draw_src.end_angle   = end_angle;
  draw_src.opa         = LV_OPA_COVER;
  // 绘制弧线
  lv_canvas_draw_arc(canvas, x, y, radius, start_angle, end_angle, &draw_src);
  lv_obj_invalidate(canvas);

  arc_img = lv_img_create(canvas);
  lv_img_set_src(arc_img, "A:rpm_normal.png");
  lv_obj_set_pos(arc_img, 0, 0);
}

void create_bg(void) {
  window = lv_obj_create(NULL);
  lv_scr_load(window);

}

void view_main() {
  create_bg();
  create_arc_on_canvas(window);
}
