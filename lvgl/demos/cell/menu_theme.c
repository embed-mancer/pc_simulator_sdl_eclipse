#include "ui_component.h"

static void Refresh() {

}

static void SwitchDisplay() {

}

static void Click(ClickTable table) {
  
}

static void OpenWindow() {

}

static void CloseWindow() {

}

static void Destory() {

}

UIComponent* MenuThemeInit() {
  UIComponent * component = (UIComponent*)lv_mem_alloc(sizeof(UIComponent));    
  if (component == NULL) {
    return NULL;
  }
  component->refresh = Refresh;
  component->click = Click;
  component->switch_display = SwitchDisplay;
  component->open_window = OpenWindow;
  component->close_window = CloseWindow;
  component->destory = Destory;

  return component;
}
