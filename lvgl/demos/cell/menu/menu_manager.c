#include "menu_manager.h"

#include <stdlib.h>

#include "vehicle_settings.h"
#include "phone.h"
#include "music.h"
#include "navigation.h"
#include "settings.h"
#include "side_bar.h"
#include "preview.h"
#include "../key/button_manager.h"

static menu_component_t* current_component = NULL;
static int page_id                         = PAGE_VEHICLE_SETTINGS;

typedef menu_component_t* (*component_factory_t)(void);

component_factory_t component_factories[] = {
    [PAGE_VEHICLE_SETTINGS] = vehicle_settings,
    [PAGE_PHONE]            = phone,
    [PAGE_MUSIC]            = music,
    [PAGE_NAVIGATION]       = navigation,
    [PAGE_SETTINGS]         = settings,
};

void menu_manager() {
  side_bar_init();
  page_id                     = PAGE_VEHICLE_SETTINGS;
  menu_component_t* component = menu_manager_create_component(page_id);
  if (component)
    menu_manager_switch_page(component);
}

void menu_manager_switch_page(menu_component_t* component) {
  if (current_component) {
    current_component->destroy();
    free(current_component);
    current_component = NULL;
  }

  if (component) {
    side_bar_update(page_id);
    current_component = component;
    current_component->open_window();
  }
}

void menu_manager_refresh() {
  if (current_component)
    current_component->refresh();
}

static void update_tick() {
}

void menu_manager_click(const click_e click) {
  update_tick();
  if (!current_component->handle_click_event(click))
    menu_manager_default_click(click);
}

void menu_manager_default_click(const click_e click) {
  uint8_t new_page_id = page_id;
  switch (click) {
  case CLICK_SHORT_SET:
    break;
  case CLICK_SHORT_BACK:
    menu_manager_back();
    return;
  case CLICK_SHORT_UP:
    new_page_id = (page_id == 0) ? (PAGE_COUNT - 1) : (page_id - 1);
    break;
  case CLICK_SHORT_DOWN:
    new_page_id = (page_e)((page_id + 1) % PAGE_COUNT);
    break;
  }

  if (new_page_id < PAGE_COUNT)
    page_id = new_page_id;
  else
    page_id = PAGE_VEHICLE_SETTINGS;

  menu_component_t* component = menu_manager_create_component(page_id);
  menu_manager_switch_page(component);
}

void menu_manager_toggle_day_night() {
}

void menu_manager_back() {
  side_bar_update(page_id);
  side_bar_show(true);
}
menu_component_t* menu_manager_create_component(page_e page) {
  if (page >= PAGE_COUNT) {
    return NULL;
  }
  return component_factories[page]();
}
