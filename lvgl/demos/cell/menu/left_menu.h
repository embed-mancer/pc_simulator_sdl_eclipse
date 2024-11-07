#ifndef LEFT_MENU_H_
#define LEFT_MENU_H_

#include "lvgl/lvgl.h"
#include "../cell.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  lv_obj_t *bg;
  lv_obj_t *img;
} menu_left_t;

void left_menu_init();
void left_menu_create_icon(menu_left_t *item, const char *img, int y);
void left_menu_update(page_t new_page);

#ifdef __cplusplus
}
#endif

#endif  // LEFT_MENU_H_
