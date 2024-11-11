#ifndef UI_HELPERS_H_
#define UI_HELPERS_H_

#include "../cell.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  int label_x;
  int label_y;
  int label_width;
  int label_height;
  int secondary_label_x;
  int image_x;
  label_color_t label_color;
  label_font_t label_font;
  const char *label_text;
  const char *secondary_label_text;
  const char *image_path;
} label_params_t;

label_params_t ui_helpers_settings_params(int label_x, int label_y,
                                          const char *label_text,
                                          const char *image_path,
                                          const char *secondary_label_text);
label_params_t ui_helpers_params(int label_x, int label_y,
                                 const char *label_text, const char *image_path,
                                 const char *secondary_label_text);
void ui_helpers_component(lv_obj_t *parent, lv_obj_t **primary_obj,
                          lv_obj_t **second_obj, label_params_t params);

#ifdef __cplusplus
}
#endif

#endif  // UI_HELPERS_H_
