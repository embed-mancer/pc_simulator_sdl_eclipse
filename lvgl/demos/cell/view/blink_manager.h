#ifndef BLINK_MANAGER_H_
#define BLINK_MANAGER_H_

#include "lvgl/lvgl.h"

#define BLINK_INTERVAL_HZ_1 500
#define BLINK_INTERVAL_HZ_2 250
#define MAX_BLINK_COUNT 5

typedef struct {
  lv_obj_t *objects[MAX_BLINK_COUNT];
  uint32_t last_update_time;
  uint32_t blink_interval;
  bool is_hidden;
  uint8_t count;
} blink_group_t;

typedef struct {
  blink_group_t group1;
  blink_group_t group2;
  uint8_t current_page;
} blink_manager_t;

void blink_manager_init(blink_manager_t *bm);
void blink_manager_start(blink_manager_t *bm);
bool blink_manager_add(blink_manager_t *bm, lv_obj_t *object,
                       uint32_t frequency);
bool blink_manager_remove(blink_manager_t *bm, lv_obj_t *object,
                          uint32_t frequency);
void blink_manager_refresh(blink_manager_t *bm);

#endif  // BLINK_MANAGER_H_
