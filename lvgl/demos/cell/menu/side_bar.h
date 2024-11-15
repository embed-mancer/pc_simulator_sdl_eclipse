#ifndef SIDE_BAR_H_
#define SIDE_BAR_H_

#include "lvgl/lvgl.h"
#include "../cell.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  lv_obj_t *bg;
  lv_obj_t *img;
} menu_left_t;

void side_bar_init();
void side_bar_update(page_e new_page);
void side_bar_show(bool is_show);
void side_bar_clear();

#ifdef __cplusplus
}
#endif

#endif  // SIDE_BAR_H_
