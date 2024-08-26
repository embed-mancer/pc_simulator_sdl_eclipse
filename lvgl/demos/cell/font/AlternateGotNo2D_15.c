/*******************************************************************************
 * Size: 15 px
 * Bpp: 1
 * Opts: --bpp 1 --size 15 --no-compress --font alternategotno2d.ttf --symbols 0123456789% --format lvgl -o AlternateGotNo2D_15.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef ALTERNATEGOTNO2D_15
#define ALTERNATEGOTNO2D_15 1
#endif

#if ALTERNATEGOTNO2D_15

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0025 "%" */
    0xe5, 0x5a, 0xa5, 0x4b, 0x1f, 0xc6, 0x95, 0x2a,
    0xd5, 0x38,

    /* U+0030 "0" */
    0x69, 0x99, 0x99, 0x99, 0x99, 0x60,

    /* U+0031 "1" */
    0x75, 0x55, 0x54,

    /* U+0032 "2" */
    0x69, 0x91, 0x12, 0x26, 0x48, 0xf0,

    /* U+0033 "3" */
    0x69, 0x91, 0x16, 0x11, 0x99, 0x60,

    /* U+0034 "4" */
    0x11, 0x8c, 0xe5, 0x2b, 0x5f, 0x10, 0x84,

    /* U+0035 "5" */
    0xf8, 0x88, 0xf9, 0x11, 0x99, 0x60,

    /* U+0036 "6" */
    0x69, 0x98, 0xf9, 0x99, 0x99, 0x60,

    /* U+0037 "7" */
    0xf1, 0x33, 0x22, 0x26, 0x66, 0x40,

    /* U+0038 "8" */
    0x69, 0x99, 0x97, 0x99, 0x99, 0x60,

    /* U+0039 "9" */
    0x69, 0x99, 0x99, 0xf1, 0x99, 0x60
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 10, .adv_w = 91, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 91, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 19, .adv_w = 91, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 25, .adv_w = 91, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 31, .adv_w = 91, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 38, .adv_w = 91, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 44, .adv_w = 91, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 50, .adv_w = 91, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 56, .adv_w = 91, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 62, .adv_w = 91, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 37, .range_length = 1, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 48, .range_length = 10, .glyph_id_start = 2,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 1, 2, 3, 4, 5, 6,
    7, 8, 9, 10
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 1, 2, 3, 4, 5, 6,
    7, 8, 9, 10
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, -4, 0, 0, 2, 0, 0, -1,
    0, 0, -9, -14, -9, -10, -8, -10,
    -9, -10, -10, -10, 0, -4, 0, 0,
    -6, 0, 0, -1, 0, 0, 0, -6,
    0, 0, 2, 0, 0, -3, 0, 0,
    0, -10, 0, 0, 4, 0, 0, -6,
    0, 0, 0, -7, 0, 0, 2, 0,
    0, -3, 0, 0, 0, -5, 0, 0,
    2, 0, 0, -1, 0, 0, 0, -6,
    -3, -4, -8, -3, -3, -2, -4, 0,
    0, -5, 0, 0, 2, 0, 0, -2,
    0, 0, 0, -4, 0, 0, 2, 0,
    0, -1, 0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 10,
    .right_class_cnt     = 10,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t AlternateGotNo2D_15 = {
#else
lv_font_t AlternateGotNo2D_15 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 11,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if ALTERNATEGOTNO2D_15*/

