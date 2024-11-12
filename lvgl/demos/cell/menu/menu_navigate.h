#ifndef MENU_NAVIGATE_H_
#define MENU_NAVIGATE_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  OPTION_PAGE,
  OPTION_DROPDOWN,
  OPTION_RADIO,
} option_type_t;

typedef struct {
  const char* name;
  int target_screen_id;
  option_type_t type;
} menu_item_t;

typedef struct {
  int id;
  const char* title;
  menu_item_t* menu_items;
  int menu_item_count;
} screen_t;

struct navigation_state_t;

typedef struct navigation_state_t {
  screen_t* current_screen;
  int selected_index;
  struct navigation_state_t* prev;
} navigation_state_t;

screen_t* menu_navigate_create_screen(int id, const char* title_text,
                                      menu_item_t* items, int item_count);
void menu_navigate_free_screen(screen_t* screen);
navigation_state_t* menu_navigate_to(navigation_state_t* current_state,
                                     menu_item_t* selected_item);
navigation_state_t* menu_navigate_go_back(navigation_state_t* current);
void print_navigation_state(navigation_state_t* state);

#ifdef __cplusplus
}
#endif

#endif  // MENU_NAVIGATE_H_
