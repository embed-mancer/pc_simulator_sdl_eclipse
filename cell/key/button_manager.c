#include "button_manager.h"
#include "../menu/menu_manager.h"
#include "../screens/menu_window.h"
#include "../screens/mobile_window.h"
#include "../screens/window_manager.h"

typedef enum {
  BUTTON_STATE_CALL,
  BUTTONG_STATE_NON_CALL,
} button_state_e;

typedef enum {
  BUTTON_ID_SHORT_UP   = 17,
  BUTTON_ID_SHORT_DOWN = 18,
  BUTTON_ID_SHORT_SET  = 10,
  BUTTON_ID_SHORT_BACK = 8
} button_id_e;

static click_e current_click        = CLICK_END;
static button_state_e current_state = BUTTONG_STATE_NON_CALL;

void button_manager_set_click(click_e click) {
  current_click = click;
}

click_e button_manager_get_click() {
  return current_click;
}

static void handle_non_call_state() {
  window_e window = window_manager_get();
  switch (window) {
  case WINDOW_MAIN:
    main_window_click(current_click);
    break;
  case WINDOW_MENU:
    menu_manager_click(current_click);
    break;
  case WINDOW_MOBILE:
    mobile_window_click(current_click);
    break;
  default:
    break;
  }
}

static void handle_call_state() {
}

void button_manager_handle() {
  if (current_state == BUTTON_STATE_CALL)
    handle_call_state();
  else
    handle_non_call_state();
}

void button_manager_refresh() {
  if (button_manager_get_click() == CLICK_END)
    return;
  current_state = BUTTONG_STATE_NON_CALL;
  button_manager_handle();
  button_manager_set_click(CLICK_END);
}

void button_manager_event(uint32_t id) {
  if (current_click != CLICK_END)
    return;

  switch (id) {
  case BUTTON_ID_SHORT_UP:
    current_click = CLICK_SHORT_UP;
    break;
  case BUTTON_ID_SHORT_DOWN:
    current_click = CLICK_SHORT_DOWN;
    break;
  case BUTTON_ID_SHORT_SET:
    current_click = CLICK_SHORT_SET;
    break;
  case BUTTON_ID_SHORT_BACK:
    current_click = CLICK_SHORT_BACK;
    break;
  default:
    break;
  }

  LOG_DEBUG("Event ID = %d processed.", id);
}
