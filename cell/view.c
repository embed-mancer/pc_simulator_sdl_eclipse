#include "view.h"
#include "lvgl/lvgl.h"

void view_main() {
  /* 创建一个屏幕 */
  lv_obj_t *screen = lv_scr_act();

  /* 创建一个图片对象 */
  lv_obj_t *img = lv_img_create(screen);
  lv_img_set_src(img, "main_bg.png"); // 使用你的图片文件
  lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);

  /* 设置遮罩 (例如显示角度为 90 度的部分) */
  lv_area_t mask_area = {0, 0, 100, 100}; // 这里定义了遮罩区域的大小
  lv_draw_mask_arc_dsc_t arc_mask;
  lv_draw_mask_arc_init(&arc_mask, &mask_area, 0, 90); // 从 0 到 90 度显示

  /* 添加遮罩 */
  int16_t mask_id = lv_draw_mask_add(&arc_mask, NULL);

  /* 在遮罩区域内绘制图像 */
  lv_obj_t *label = lv_label_create(screen);
  lv_label_set_text(label, "Angle Masked Image");
  lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

  /* 移除遮罩 */
  // lv_draw_mask_remove(mask_id);
}
