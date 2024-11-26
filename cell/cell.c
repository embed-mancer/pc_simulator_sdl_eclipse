#include "cell.h"
#include "config/config.h"
#include "data/veh_data.h"

void cell_init() {
  config_initialize();
  veh_init();
}
