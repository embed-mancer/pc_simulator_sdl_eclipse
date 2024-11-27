#include "cell.h"
#include "config/config.h"
#include "data/veh_data.h"

static void cache_images() {
  uint32_t start_time = lv_tick_get();
  char sz[MAX_IMAGE_CHARS];
  for (int i = 10; i < 110; ++i) {
    snprintf(sz, MAX_IMAGE_CHARS, RES_PRFIX "home/night/rpm/%d.png", i + 1);
    ui_helpers_cache_images(NULL, 1, sz);
  }
  uint32_t end_time = lv_tick_get();
  LOG_DEBUG("Caching images took %d ms.", end_time - start_time);
}

void cell_init() {
  config_initialize();
  veh_init();
  tool_init();
  cache_images();
}
