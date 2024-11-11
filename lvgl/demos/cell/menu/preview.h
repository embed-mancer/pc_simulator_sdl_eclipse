#ifndef PREVIEW_H_
#define PREVIEW_H_

#include "menu_manager.h"

#ifdef __cplusplus
extern "C" {
#endif

void preivew_init(page_t page);
void preview_switch(page_t page);
void preview_close();
void preview_set_common_elements(page_t page);
void preview_set_vehicle_details();
void preview_phone();
void preview_music();
void preview_navigation();
void preview_settings();

#ifdef __cplusplus
}
#endif

#endif  // PREVIEW_H_
