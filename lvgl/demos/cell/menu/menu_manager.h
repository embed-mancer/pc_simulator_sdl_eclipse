#ifndef MENU_MANAGER_H_
#define MENU_MANAGER_H_

#include "../cell.h"
#include "menu_component.h"

#ifdef __cplusplus
extern "C" {
#endif

void menu_manager();
void menu_manager_switch_page(menu_component_t*);
void menu_manager_refresh();
void menu_manager_click(const click_t);
void menu_manager_default_click(const click_t);
void menu_manager_toggle_day_night();
menu_component_t* menu_manager_create_component(page_t);

#ifdef __cplusplus
}
#endif

#endif  // MENU_MANAGER_H_
