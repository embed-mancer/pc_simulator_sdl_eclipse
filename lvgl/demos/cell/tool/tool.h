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
