#ifndef SETTINGS_H_
#define SETTINGS_H_

#include "menu_component.h"

#ifdef __cplusplus
extern "C" {
#endif

menu_component_t* settings();
void settings_clear_elements();
void settings_device_connection();
void settings_mobile_device();
void settings_helmet1();
void settings_helmet2();
void settings_option1();
void settings_option2();
void settings_auto_brightness();
void settings_unit();
void settings_time();
void settings_language();
void settings_upgrade();
void settings_about();

#ifdef __cplusplus
}
#endif

#endif  // SETTINGS_H_
