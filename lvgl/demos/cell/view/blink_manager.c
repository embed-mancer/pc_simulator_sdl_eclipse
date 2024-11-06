#include "blink_manager.h"
#include "../cell.h"

static void update_visibility(blink_group_t *group, uint32_t now) {
  if (lv_tick_elaps(group->last_update_time) > group->blink_interval) {
    group->last_update_time = now;
    group->is_hidden = !group->is_hidden;

    for (uint8_t i = 0; i < group->count; i++) {
      if (group->is_hidden) {
        lv_obj_add_flag(group->objects[i], LV_OBJ_FLAG_HIDDEN);
      } else {
        lv_obj_clear_flag(group->objects[i], LV_OBJ_FLAG_HIDDEN);
      }
    }
  }
}

void blink_manager_refresh(blink_manager_t *bm) {
  uint32_t now = lv_tick_get();
  update_visibility(&bm->group1, now);
  update_visibility(&bm->group2, now);
}

static void init_blink_group(blink_group_t *group, uint32_t blink_interval) {
  memset(group->objects, 0, sizeof(group->objects));
  group->count = 0;
  group->is_hidden = true;
  group->last_update_time = 0;
  group->blink_interval = blink_interval;
}

static bool add_to_blink_group(blink_group_t *group, lv_obj_t *object) {
  if (group->count >= MAX_BLINK_COUNT) {
    return false;
  }
  group->objects[group->count++] = object;
  return true;
}

static bool remove_from_blink_group(blink_group_t *group, lv_obj_t *object) {
  for (uint8_t i = 0; i < group->count; i++) {
    if (group->objects[i] == object) {
      group->objects[i] = group->objects[--group->count];
      group->objects[group->count] = NULL;
      return true;
    }
  }
  return false;
}

void blink_manager_init(blink_manager_t *bm) {
  init_blink_group(&bm->group1, BLINK_INTERVAL_HZ_1);
  init_blink_group(&bm->group2, BLINK_INTERVAL_HZ_2);
}

void blink_manager_start(blink_manager_t *bm) {
  bm->group1.last_update_time = lv_tick_get();
  bm->group2.last_update_time = lv_tick_get();
}

bool blink_manager_add(blink_manager_t *bm, lv_obj_t *object,
                       uint32_t frequency) {
  switch (frequency) {
    case BLINK_INTERVAL_HZ_1:
      return add_to_blink_group(&bm->group1, object);
    case BLINK_INTERVAL_HZ_2:
      return add_to_blink_group(&bm->group2, object);
    default:
      return false;
  }
}

bool blink_manager_remove(blink_manager_t *bm, lv_obj_t *object,
                          uint32_t frequency) {
  switch (frequency) {
    case BLINK_INTERVAL_HZ_1:
      return remove_from_blink_group(&bm->group1, object);
    case BLINK_INTERVAL_HZ_2:
      return remove_from_blink_group(&bm->group2, object);
    default:
      return false;
  }
}
