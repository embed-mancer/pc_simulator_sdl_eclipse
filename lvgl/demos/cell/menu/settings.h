#ifndef SETTINGS_H_
#define SETTINGS_H_

#include "menu_component.h"

#ifdef __cplusplus
extern "C" {
#endif

menu_component_t* settings();
void settings_device();
void settings_option1();
void settings_option2();
void settings_content();
void settings_upgrade();
void settings_about();

#ifdef __cplusplus
}
#endif

#endif  // SETTINGS_H_
