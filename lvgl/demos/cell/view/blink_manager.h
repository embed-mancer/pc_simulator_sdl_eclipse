#ifndef BLINK_MANAGER_H_
#define BLINK_MANAGER_H_

#include "lvgl/lvgl.h"

#define BLINK_INTERVAL_HZ_1 500
#define BLINK_INTERVAL_HZ_2 250
#define MAX_BLINK_COUNT 5

typedef struct {
  lv_obj_t *objects[MAX_BLINK_COUNT ];
  uint32_t last_update_time;
  uint32_t blink_interval;
  bool is_hidden;
  uint8_t count;
} BlinkGroup;

typedef struct {
  BlinkGroup group1;
  BlinkGroup group2;
  uint8_t current_page;
} BlinkManager;

void BlinkManagerInit(BlinkManager *bm);
void BlinkManagerStart(BlinkManager *bm);
bool BlinkManagerAdd(BlinkManager *bm, lv_obj_t *object, int frequency);
bool BlinkManagerRemove(BlinkManager *bm, lv_obj_t *object, int frequency);
void BlinkManagerRefresh(BlinkManager *bm);

#endif  // BLINK_MANAGER_H_
