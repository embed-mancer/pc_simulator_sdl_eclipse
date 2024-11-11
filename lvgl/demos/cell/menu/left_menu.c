#include "left_menu.h"
#include "../cell.h"
#include "../language/lang.h"

#define MENU_ITEM_COUNT 5
#define MENU_ITEM_WIDTH 110
#define MENU_ITEM_HEIGHT 90
#define MENU_ITEM_START_Y 15
#define MENU_ITEM_Y_GAP 90
#define BACKGROUND_COLOR lv_color_make(0x1e, 0x1f, 0x1f)
#define ACTIVE_COLOR lv_color_make(0x45, 0xc7, 0xe9)
#define IMAGE_X_POSITION 37
#define IMAGE_Y_POSITION 47

static menu_left_t icons[MENU_ITEM_COUNT];
static lv_obj_t* bg = NULL;
static page_t current_page = 0;
extern lv_obj_t* menu_window;

void left_menu_init() {
  initialize_background(&bg, menu_window, 0, 0, MENU_ITEM_WIDTH, 480,
                        BACKGROUND_COLOR);

  const char* icon_paths[MENU_ITEM_COUNT] = {
      RES_PRFIX "menu/motor_icon_black.png", RES_PRFIX "menu/phone_icon.png",
      RES_PRFIX "menu/music_icon.png", RES_PRFIX "menu/navigation_icon.png",
      RES_PRFIX "menu/settings_icon.png"};

  for (int i = 0; i < MENU_ITEM_COUNT; ++i) {
    int y_position = MENU_ITEM_START_Y + i * MENU_ITEM_Y_GAP;
    left_menu_create_icon(&icons[i], icon_paths[i], y_position);
  }

  set_screen_color(icons[0].bg, ACTIVE_COLOR);
}

void left_menu_create_icon(menu_left_t* item, const char* img, int y) {
  initialize_background(&item->bg, menu_window, 0, y, MENU_ITEM_WIDTH,
                        MENU_ITEM_HEIGHT, BACKGROUND_COLOR);
  image_pos_t pos = create_image_pos(img, IMAGE_X_POSITION, IMAGE_Y_POSITION);
  create_img(item->bg, &item->img, pos);
}

void left_menu_update(page_t new_page) {
  if (new_page < 0 || new_page >= MENU_ITEM_COUNT) return;

  set_screen_color(icons[current_page].bg, BACKGROUND_COLOR);
  set_screen_color(icons[new_page].bg, ACTIVE_COLOR);
  current_page = new_page;
}

void left_menu_show(bool is_show) {
  if (is_show) {
    lv_obj_clear_flag(bg, LV_OBJ_FLAG_HIDDEN);
    for (int i = 0; i < 5; ++i) {
      lv_obj_clear_flag(icons[i].bg, LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(icons[i].img, LV_OBJ_FLAG_HIDDEN);
    } 
  } else {
    lv_obj_add_flag(bg, LV_OBJ_FLAG_HIDDEN);
    for (int i = 0; i < 5; ++i) {
      lv_obj_add_flag(icons[i].bg, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(icons[i].img, LV_OBJ_FLAG_HIDDEN);
    } 
  }
}
