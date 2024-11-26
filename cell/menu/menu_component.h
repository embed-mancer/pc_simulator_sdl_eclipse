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
  bool (*handle_click_event)(const click_e);
  void (*toggle_day_night)();
  void (*destroy)();
  void (*open_window)();
  void (*close_window)();
  meter_mode_e last_mode;
  language_e last_lang;
} menu_component_t;

typedef enum {
  DIRECTION_UP,
  DIRECTION_DOWN,
} direction_e;

typedef enum {
  SETTING_DISPLAY,
  SETTING_BACKLIGHT,
  SETTING_BLUETOOTH,
  SETTING_CLOCK,
  SETTING_UNIT,
  SETTING_LANGUAGE,
  SETTING_VEHICLE,
  SETTING_FAULT,
  SETTING_MOBILE,
  SETTING_MAIN,
} setting_option_e;

void free_component(menu_component_t *component);
menu_component_t *allocate_component();
void init_component(menu_component_t *component, void (*refresh)(),
                    bool (*handle_click_event)(const click_e),
                    void (*toggle_day_night)(), void (*destroy)(),
                    void (*open_window)(), void (*close_window)());
void create_item(item_t **, int, text_id_e, const char *, bool);
void set_item_color(item_t **, bool);
void update_index(int direction);

#ifdef __cplusplus
}
#endif

#endif  // MENU_COMPONENT_H_
