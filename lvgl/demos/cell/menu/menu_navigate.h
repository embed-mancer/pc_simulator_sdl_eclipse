#ifndef MENU_NAVIGATE_H_
#define MENU_NAVIGATE_H_

#include "lvgl/lvgl.h"
#include "menu_component.h"
#include "button_control.h"
#include "../screens/menu_window.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  OPTION_PAGE,
  OPTION_DROPDOWN,
  OPTION_RADIO,
  OPTION_NULL,
} option_type_e;

typedef struct {
  const char* name;
  int target_screen_id;
  option_type_e type;
} menu_item_t;

typedef struct {
  int id;
  const char* title;
  menu_item_t* menu_items;
  int menu_item_count;
  lv_obj_t** elements;
  menu_component_t* component;
  int element_count;
  void (*on_return)();
} screen_t;

struct navigation_state_t;

typedef struct navigation_state_t {
  screen_t* current_screen;
  int selected_index;
  struct navigation_state_t* prev;
} navigation_state_t;

extern navigation_state_t* nav_state;

navigation_state_t* menu_navigate_create(screen_t* screen);
screen_t* menu_navigate_create_screen(int id, const char* title_text,
                                      menu_item_t* items, int item_count,
                                      int element_count);
void menu_navigate_free_screen(screen_t** screen);
void menu_navigate_free(navigation_state_t** state);
void menu_navigate_to(navigation_state_t** current_state, screen_t* new_screen);
void menu_navigate_go_back(navigation_state_t** current);
void print_navigation_state(navigation_state_t* state);
void menu_navigate_hide_screen(screen_t* screen);
void menu_navigate_show_screen(screen_t* screen);

#ifdef __cplusplus
}
#endif

#endif  // MENU_NAVIGATE_H_
