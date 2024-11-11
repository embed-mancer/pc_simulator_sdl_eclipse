#include "button_manager.h"
#include "../menu/menu_manager.h"

typedef enum {
  BUTTON_STATE_CALL,
  BUTTONG_STATE_NON_CALL,
} button_state_t;

static click_t current_click = CLICK_END;
static button_state_t current_state = BUTTONG_STATE_NON_CALL;

void button_manager_set_click(click_t click) { current_click = click; }

click_t button_manager_get_click() { return current_click; }

static void handle_non_call_state() {
  window_t window = get_window();
  switch (window) {
    case WINDOW_MAIN:
      break;
    case WINDOW_MENU:
      menu_manager_click(current_click);
      break;
    case WINDOW_NAVIGATION:
      break;
    default:
      break;
  }
}

static void handle_call_state() {
  if (current_click == CLICK_SHORT_BACK) {
    int current_state = 0;
  } else if (current_click == CLICK_SHORT_SET) {
    int current_state = 0;
  }
}

void button_manager_handle() {
  if (current_state == BUTTON_STATE_CALL)
    handle_call_state();
  else
    handle_non_call_state();
}

void button_manager_refresh() {
  if (button_manager_get_click() == CLICK_END) return;
  current_state = BUTTONG_STATE_NON_CALL;
  button_manager_handle();
  button_manager_set_click(CLICK_END);
}

void button_manager_event(uint32_t id) {
  if (button_manager_get_click() != CLICK_END) return;

  printf("id = %d\n", id);
  switch (id) {
    case 17:
      current_click = CLICK_SHORT_UP;
      break;
    case 18:
      current_click = CLICK_SHORT_DOWN;
      break;
    case 10:
      current_click = CLICK_SHORT_SET;
      break;
    case 8:
      current_click = CLICK_LONG_BACK;
    default:
      break;
  }
}
