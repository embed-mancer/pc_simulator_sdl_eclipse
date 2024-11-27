#include "menu_navigate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strdup(const char *str) {
  char *copy = malloc(strlen(str) + 1);
  if (copy)
    strcpy(copy, str);
  return copy;
}

navigation_state_t *menu_navigate_create(screen_t *screen) {
  navigation_state_t *state = malloc(sizeof(navigation_state_t));
  state->current_screen     = screen;
  state->selected_index     = 0;
  state->prev               = NULL;
  return state;
}

screen_t *menu_navigate_create_screen(int id, const char *title_text,
                                      menu_item_t *items, int item_count,
                                      int element_count) {
  screen_t *screen = malloc(sizeof(screen_t));
  if (!screen)
    return NULL;

  screen->id    = id;
  screen->title = strdup(title_text);
  if (!screen->title) {
    free(screen);
    return NULL;
  }
  screen->menu_items      = items;
  screen->menu_item_count = item_count;
  screen->element_count   = element_count;
  screen->on_return       = NULL;

  // screen->elements = malloc(element_count * sizeof(lv_obj_t *));
  screen->elements = calloc(element_count, sizeof(lv_obj_t *));
  if (!screen->elements) {
    free((char *)screen->title);
    free(screen);
    return NULL;
  }

  // memset(screen->elements, 0, element_count * sizeof(lv_obj_t *));

  return screen;
}

void menu_navigate_free_screen(screen_t **screen) {
  if (screen && *screen) {
    screen_t *current_screen = *screen;

    if (current_screen->title) {
      free((char *)current_screen->title);
    }

    if (current_screen->menu_items) {
      free(current_screen->menu_items);
    }

    if (current_screen->elements) {
      for (int i = 0; i < current_screen->element_count; ++i) {
        if (current_screen->elements[i]) {
          lv_obj_del(current_screen->elements[i]);
        }
      }
      free(current_screen->elements);
    }

    if (current_screen->component) {
      free_component(current_screen->component);
    }

    free(current_screen);
    *screen = NULL;
  }
}

void menu_navigate_free(navigation_state_t **state) {
  if (!(*state))
    return;
  menu_navigate_free_screen(&(*state)->current_screen);
  free(*state);
  *state = NULL;
}

void menu_navigate_to(navigation_state_t **current_state,
                      screen_t *new_screen) {
  if (!new_screen)
    return;

  navigation_state_t *new_state = malloc(sizeof(navigation_state_t));
  if (!new_state)
    return;

  new_state->current_screen = new_screen;
  new_state->selected_index = 0;
  new_state->prev           = *current_state;

  // hide current screen
  if (*current_state && (*current_state)->current_screen) {
    menu_navigate_hide_screen((*current_state)->current_screen);
  }
  menu_navigate_show_screen(new_screen);

  *current_state = new_state;
}

void menu_navigate_go_back(navigation_state_t **current_state) {
  if (*current_state && (*current_state)->prev) {
    navigation_state_t *prev_state = (*current_state)->prev;
    menu_navigate_free(current_state);
    menu_navigate_show_screen(prev_state->current_screen);
    *current_state        = prev_state;
    screen_t *prev_screen = (*current_state)->current_screen;
    if (prev_screen->on_return) {
      prev_screen->on_return();
    }
    // prev_screen->component->refresh();
  }
}

void print_navigation_state(navigation_state_t *state) {
  if (state && state->current_screen) {
    LOG_DEBUG("Current Screen: %s", state->current_screen->title);
    if (state->selected_index < state->current_screen->menu_item_count) {
      LOG_DEBUG("Selected Item: %s",
             state->current_screen->menu_items[state->selected_index].name);
    } else {
      LOG_DEBUG("Selected index out of range.\n");
    }
  } else {
    LOG_DEBUG("Navigation state or current screen is NULL.\n");
  }
}

void menu_navigate_hide_screen(screen_t *screen) {
  if (screen && screen->elements)
    for (int i = 0; i < screen->element_count; ++i)
      if (screen->elements[i])
        lv_obj_add_flag(screen->elements[i], LV_OBJ_FLAG_HIDDEN);
}

void menu_navigate_show_screen(screen_t *screen) {
  if (screen && screen->elements)
    for (int i = 0; i < screen->element_count; ++i)
      if (screen->elements[i])
        lv_obj_clear_flag(screen->elements[i], LV_OBJ_FLAG_HIDDEN);
}
