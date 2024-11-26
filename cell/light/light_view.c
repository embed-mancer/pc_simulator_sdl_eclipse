#include "light_view.h"

static void light_view_initialize_icons(light_view_t *view) {
  memset(view->icons, 0, sizeof(view->icons));

  int needed_icons[] = {SIGNAL_LIGHT_TURN_LEFT,    SIGNAL_LIGHT_AUTO_START_STOP,
                        SIGNAL_LIGHT_TIRE,         SIGNAL_LIGHT_HIGH_BEAM,
                        SIGNAL_LIGHT_OIL_PRESSURE, SIGNAL_LIGHT_ABS,
                        SIGNAL_LIGHT_WIFI,         SIGNAL_LIGHT_BT_PAIR,
                        SIGNAL_LIGHT_BT_ICON,      SIGNAL_LIGHT_VOLTAGE};

  for (size_t i = 0; i < sizeof(needed_icons) / sizeof(needed_icons[0]); i++) {
    view->icons[needed_icons[i]].is_needed = true;
  }
}

void light_view_init(light_view_t *view) {
  light_view_initialize_icons(view);
  light_view_create(view);
}

void light_view_create(light_view_t *view) {
  for (size_t i = 0; i < sizeof(view->icons) / sizeof(view->icons[0]); i++) {
    if (view->icons[i].is_needed) {
      ui_helpers_create_image(view->background, &view->icons[i].obj,
                              view->light->pos[i]);
    }
  }
}

void light_view_display(icon_t *icon, display_state_e table) {
  if (!icon->is_needed)
    return;
  switch (table) {
  case DISPLAY_STATE_HIDE:
    lv_obj_add_flag(icon->obj, LV_OBJ_FLAG_HIDDEN);
    break;
  case DISPLAY_STATE_SHOW:
    lv_obj_clear_flag(icon->obj, LV_OBJ_FLAG_HIDDEN);
    break;
  }
}
