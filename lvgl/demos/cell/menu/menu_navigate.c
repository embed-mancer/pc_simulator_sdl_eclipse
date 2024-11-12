#include "menu_navigate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* strdup(const char* str) {
    char* copy = malloc(strlen(str) + 1);
    if (copy) strcpy(copy, str);
    return copy;
}

screen_t *menu_navigate_create_screen(int id, const char *title_text,
                                      menu_item_t *items, int item_count) {
  screen_t *screen = malloc(sizeof(screen_t));
  if (!screen) return NULL;

  screen->id = id;
  screen->title = strdup(title_text);
  if (!screen->title) {
    free(screen);
    return NULL;
  }
  screen->menu_items = items;
  screen->menu_item_count = item_count;

  return screen;
}

void menu_navigate_free_screen(screen_t *screen) {
  if (screen) {
    if (screen->title)
      free((void *)screen->title);
    if (screen->menu_items)
      free(screen->menu_items);
    free(screen);
  }
}

navigation_state_t *menu_navigate_to(navigation_state_t *current_state,
                                     menu_item_t *selected_item) {
  if (selected_item->type == OPTION_PAGE &&
      selected_item->target_screen_id >= 0) {
    navigation_state_t *new_state = malloc(sizeof(navigation_state_t));
    if (!new_state) return NULL;

    new_state->selected_index = 0;
    new_state->prev = current_state;
    return new_state;
  } else if (selected_item->type == OPTION_DROPDOWN) {
    current_state->selected_index =
        (current_state->selected_index + 1) %
        current_state->current_screen->menu_item_count;
    printf("Dropdown option selected: %s\n", selected_item->name);
  }
  return current_state;
}

navigation_state_t *menu_navigate_go_back(navigation_state_t *current_state) {
  if (current_state && current_state->prev) {
    navigation_state_t *prev_state = current_state->prev;
    menu_navigate_free_screen(current_state->current_screen);
    free(current_state);
    return prev_state;
  }
  return current_state;
}

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
