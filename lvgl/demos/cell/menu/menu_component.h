#ifndef MENU_COMPONENT_H_
#define MENU_COMPONENT_H_

#include "../cell.h"
#include "../language/lang.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  lv_obj_t *bg;
  lv_obj_t *title;
  lv_obj_t *arrow;
  lv_obj_t *num;
} item_t;

typedef struct {
  void (*refresh)();
  bool (*handle_click_event)(const click_t);
  void (*toggle_day_night)();
  void (*destroy)();
  void (*open_window)();
  void (*close_window)();
} menu_component_t;

menu_component_t *allocate_component();
void init_component(menu_component_t *component, void (*refresh)(),
                    bool (*handle_click_event)(const click_t),
                    void (*toggle_day_night)(), void (*destroy)(),
                    void (*open_window)(), void (*close_window)());
void create_item(item_t **, int, text_id_t, const char *, bool);
void set_item_color(item_t **, bool);

#ifdef __cplusplus
}
#endif

#endif  // MENU_COMPONENT_H_
