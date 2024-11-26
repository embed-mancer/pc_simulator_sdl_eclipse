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
  label_color_e label_color;
  label_font_e label_font;
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

void calclate_vehicle_y(int *y_positon, int base, int step);
void ui_helpers_menu_image(lv_obj_t **elements, const char *suffix,
                           int element_index, int x, int y);
/**
 * @brief Creates an image object on the given background object.
 *
 * @param[in] bg The parent object to which the image will be added.
 * @param[out] lv Pointer to the created image object.
 * @param[in] pos The position and properties of the image.
 */
void ui_helpers_create_image(lv_obj_t *bg, lv_obj_t **lv, image_pos_t pos);

/**
 * @brief Creates a label object on the given background object.
 *
 * @param[in] bg The parent object to which the label will be added.
 * @param[out] lv Pointer to the created label object.
 * @param[in] pos The position and properties of the label.
 */
void ui_helpers_create_label(lv_obj_t *bg, lv_obj_t **lv, label_pos_t pos);

/**
 * @brief Creates a left-aligned label at the center of the specified parent
 * object.
 *
 * @param[in] parent The parent object to which the label will be added.
 * @param[out] label Pointer to the created label object.
 * @param[in] x The x-coordinate of the label.
 * @param[in] y The y-coordinate of the label.
 * @param[in] width The width of the label.
 * @param[in] height The height of the label.
 * @param[in] color The color of the label.
 * @param[in] font The font of the label.
 * @param[in] text The text content of the label.
 */
void ui_helpers_create_label_left(lv_obj_t *parent, lv_obj_t **label, int x,
                                  int y, int width, int height,
                                  label_color_e color, label_font_e font,
                                  const char *text);

/**
 * @brief Creates a right-aligned label at the center of the specified parent
 * object.
 *
 * @param[in] parent The parent object to which the label will be added.
 * @param[out] label Pointer to the created label object.
 * @param[in] x The x-coordinate of the label.
 * @param[in] y The y-coordinate of the label.
 * @param[in] width The width of the label.
 * @param[in] height The height of the label.
 * @param[in] color The color of the label.
 * @param[in] font The font of the label.
 * @param[in] text The text content of the label.
 */
void ui_helpers_create_label_right(lv_obj_t *parent, lv_obj_t **label, int x,
                                   int y, int width, int height,
                                   label_color_e color, label_font_e font,
                                   const char *text);

/**
 * @brief Creates a right-aligned label at the center of the specified parent
 * object.
 *
 * @param[in] parent The parent object to which the label will be added.
 * @param[out] label Pointer to the created label object.
 * @param[in] x The x-coordinate of the label.
 * @param[in] y The y-coordinate of the label.
 * @param[in] width The width of the label.
 * @param[in] height The height of the label.
 * @param[in] color The color of the label.
 * @param[in] font The font of the label.
 * @param[in] text The text content of the label.
 */
void ui_helpers_create_label_center(lv_obj_t *parent, lv_obj_t **label, int x,
                                    int y, int width, int height,
                                    label_color_e color, label_font_e font,
                                    const char *text);
/**
 * @brief Creates an image position structure.
 *
 * @param[in] image_path The path to the image file.
 * @param[in] x The x-coordinate of the image position.
 * @param[in] y The y-coordinate of the image position.
 * @return The created image position structure.
 */
image_pos_t ui_helpers_init_image_position(const char *image_path, int x,
                                           int y);

/**
 * @brief Creates a label value structure.
 *
 * @param[in] str The string value of the label.
 * @return The created label value structure.
 */
label_value_t ui_helpers_init_label_value(const char *str);

/**
 * @brief Creates a label position structure.
 *
 * @param[in] x The x-coordinate of the label position.
 * @param[in] y The y-coordinate of the label position.
 * @param[in] w The width of the label.
 * @param[in] h The height of the label.
 * @param[in] color The color of the label.
 * @param[in] font The font of the label.
 * @param[in] type The type of the label value.
 * @param[in] text The label value.
 * @return The created label position structure.
 */
label_pos_t ui_helpers_init_label_position(int x, int y, int w, int h,
                                           label_color_e color,
                                           label_font_e font, value_type_e type,
                                           label_value_t text);
/**
 * @brief Initializes a background object with the specified properties.
 *
 * @param[out] bg Pointer to the created background object.
 * @param[in] parent The parent object to which the background will be added.
 * @param[in] x The x-coordinate of the background.
 * @param[in] y The y-coordinate of the background.
 * @param[in] width The width of the background.
 * @param[in] height The height of the background.
 * @param[in] color The color of the background.
 */
void initialize_background(lv_obj_t **bg, lv_obj_t *parent, int x, int y,
                           int width, int height, lv_color_t color);
void ui_helpers_centered_y_positions(int *y_positions, int count,
                                     int item_height);
void ui_helpers_set_element_style(lv_obj_t *element, bool selected,
                                  lv_color_t color);
#ifdef __cplusplus
}
#endif

#endif  // UI_HELPERS_H_
