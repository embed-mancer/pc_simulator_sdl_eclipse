#include <stdio.h>
#include <string.h>

#include "../cell.h"
#include "lvgl/lvgl.h"

/**
 * @brief Initializes the tool module.
 */
void tool_init();

/**
 * @brief Initializes the color map used by the tool.
 */
void tool_init_color_map();

/**
 * @brief Retrieves the color corresponding to the given label color.
 *
 * @param[in] color The label color enumeration value.
 * @return The corresponding lv_color_t value.
 */
lv_color_t tool_get_color(label_color_e color);

/**
 * @brief Retrieves the font corresponding to the given label font.
 *
 * @param[in] font The label font enumeration value.
 * @return A pointer to the corresponding lv_font_t.
 */
const lv_font_t* tool_get_font(label_font_e font);

/**
 * @brief Retrieves the width of the given label font.
 *
 * @param[in] font The label font enumeration value.
 * @return The width of the font in pixels.
 */
lv_coord_t tool_get_width(label_font_e font);

/**
 * @brief Replaces all occurrences of a substring in a string with a new
 * substring.
 *
 * @param[in,out] str The string in which to perform the replacement.
 * @param[in] old_substr The substring to be replaced.
 * @param[in] new_substr The substring to replace with.
 */
void replace_substring(char* str, const char* old_substr,
                       const char* new_substr);

/**
 * @brief Creates an image object on the given background object.
 *
 * @param[in] bg The parent object to which the image will be added.
 * @param[out] lv Pointer to the created image object.
 * @param[in] pos The position and properties of the image.
 */
void create_img(lv_obj_t* bg, lv_obj_t** lv, image_pos_t pos);

/**
 * @brief Creates a label object on the given background object.
 *
 * @param[in] bg The parent object to which the label will be added.
 * @param[out] lv Pointer to the created label object.
 * @param[in] pos The position and properties of the label.
 */
void create_label(lv_obj_t* bg, lv_obj_t** lv, label_pos_t pos);

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
void create_center_left_label(lv_obj_t* parent, lv_obj_t** label, int x, int y,
                              int width, int height, label_color_e color,
                              label_font_e font, const char* text);

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
void create_center_right_label(lv_obj_t* parent, lv_obj_t** label, int x, int y,
                               int width, int height, label_color_e color,
                               label_font_e font, const char* text);

/**
 * @brief Creates an image position structure.
 *
 * @param[in] image_path The path to the image file.
 * @param[in] x The x-coordinate of the image position.
 * @param[in] y The y-coordinate of the image position.
 * @return The created image position structure.
 */
image_pos_t create_image_pos(const char* image_path, int x, int y);

/**
 * @brief Creates a label value structure.
 *
 * @param[in] str The string value of the label.
 * @return The created label value structure.
 */
label_value_t create_label_value(const char* str);

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
label_pos_t create_label_pos(int x, int y, int w, int h, label_color_e color,
                             label_font_e font, value_type_e type,
                             label_value_t text);

/**
 * @brief Retrieves the theme color used by the tool.
 *
 * @return The current theme color.
 */
lv_color_t tool_get_theme_color();

/**
 * @brief Toggles between day and night mode for a given image.
 *
 * @param[in,out] image The image to toggle between day and night mode.
 */
void tool_toggle_day_night(char* image);

/**
 * @brief Sets the text color of an object based on the current mode
 * (day/night).
 *
 * @param[in] obj The object whose text color will be set.
 * @param[in] night_color The color to set in night mode.
 * @param[in] day_color The color to set in day mode.
 */
void tool_set_text_on_mode(lv_obj_t* obj, int night_color, int day_color);

/**
 * @brief Sets the text color of an object based on the current mode (day/night)
 * and updates the color property.
 *
 * @param[in] obj The object whose text color will be set.
 * @param[in,out] color_prop Pointer to the color property to be updated.
 * @param[in] night_color The color to set in night mode.
 * @param[in] day_color The color to set in day mode.
 */
void tool_set_text_on_mode_and_update(lv_obj_t* obj, label_color_e* color_prop,
                                      int night_color, int day_color);

/**
 * @brief Retrieves the theme suffix used by the tool.
 *
 * @return The current theme suffix as a string.
 */
const char* tool_get_theme_suffix();

/**
 * @brief Retrieves the base color used by the tool.
 *
 * @return The base label color enumeration value.
 */
label_color_e tool_get_color_base();

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
void initialize_background(lv_obj_t** bg, lv_obj_t* parent, int x, int y,
                           int width, int height, lv_color_t color);