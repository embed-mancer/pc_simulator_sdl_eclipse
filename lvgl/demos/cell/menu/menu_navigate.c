#include "menu_navigate.h"
#include <stdio.h>
#include <stdlib.h>

// Function to navigate to the target option
navigation_state_t *menu_navigate_to(navigation_state_t *current_state,
                                menu_item_t *selected_item,
                                screen_t *new_screen) {
  if (selected_item->type == OPTION_PAGE &&
      selected_item->target_screen_id >= 0) {
    // If it's a page navigation option, create a new navigation state
    navigation_state_t *new_state = malloc(sizeof(navigation_state_t));
    new_state->current_screen =
        new_screen;  
    new_state->selected_index = 0;
    new_state->prev = current_state;
    return new_state;
  } else if (selected_item->type == OPTION_DROPDOWN) {
    // If it's a dropdown option, remain in the current screen, just change the
    // selected item position
    current_state->selected_index++;
    if (current_state->selected_index >=
        current_state->current_screen->menu_item_count) {
      current_state->selected_index = 0;  // Wrap around to the first item
    }
    printf("Dropdown option selected: %s\n", selected_item->name);
  }
  return current_state;  // For dropdown, return the current state
}

// Function to go back to the previous screen
navigation_state_t *menu_navigate_go_back(navigation_state_t *current_state) {
  if (current_state->prev) {
    navigation_state_t *prev_state = current_state->prev;
    free(current_state);  // Free the memory for the current state
    return prev_state;    // Return to the previous state
  }
  return current_state;  // If no previous state, stay in the current state
}

// Print the current screen and selected item
void print_navigation_state(navigation_state_t *state) {
  if (state && state->current_screen) {
    printf("Current Screen: %s\n", state->current_screen->title);
    if (state->selected_index < state->current_screen->menu_item_count) {
      printf("Selected Item: %s\n",
             state->current_screen->menu_items[state->selected_index].name);
    } else {
      printf("Selected index out of range.\n");
    }
  } else {
    printf("Navigation state or current screen is NULL.\n");
  }
}
