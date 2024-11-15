#ifndef PREVIEW_H_
#define PREVIEW_H_

#include "menu_manager.h"

#ifdef __cplusplus
extern "C" {
#endif

void preview_set_vehicle_details(lv_obj_t **elements);
void preview_phone(lv_obj_t **elements);
void preview_music(lv_obj_t **elements);
void preview_navigation(lv_obj_t **elements);
void preview_settings(lv_obj_t **elements);

#ifdef __cplusplus
}
#endif

#endif  // PREVIEW_H_
