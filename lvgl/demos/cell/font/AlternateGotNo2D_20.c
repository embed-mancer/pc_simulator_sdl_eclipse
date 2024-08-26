/*******************************************************************************
 * Size: 20 px
 * Bpp: 1
 * Opts: --bpp 1 --size 20 --no-compress --font alternategotno2d.ttf --symbols ODO: , MI0123456789 --format lvgl -o AlternateGotNo2D_20.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef ALTERNATEGOTNO2D_20
#define ALTERNATEGOTNO2D_20 1
#endif

#if ALTERNATEGOTNO2D_20

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+002C "," */
    0xda,

    /* U+0030 "0" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c,
    0xf3, 0x78,

    /* U+0031 "1" */
    0x37, 0xf3, 0x33, 0x33, 0x33, 0x33, 0x30,

    /* U+0032 "2" */
    0x7b, 0x3c, 0xf3, 0xc, 0x71, 0x8e, 0x31, 0xc6,
    0x30, 0xfc,

    /* U+0033 "3" */
    0x7b, 0x3c, 0xc3, 0xc, 0xe0, 0xc3, 0xf, 0x3c,
    0xf3, 0x78,

    /* U+0034 "4" */
    0x18, 0x70, 0xe1, 0xc7, 0x8b, 0x16, 0x6c, 0xfe,
    0x30, 0x60, 0xc1, 0x80,

    /* U+0035 "5" */
    0xff, 0xc, 0x30, 0xfb, 0x30, 0xc3, 0xf, 0x3c,
    0xf3, 0x78,

    /* U+0036 "6" */
    0x7b, 0x3c, 0xf0, 0xc3, 0xec, 0xf3, 0xcf, 0x3c,
    0xf3, 0x78,

    /* U+0037 "7" */
    0xfc, 0x30, 0xc6, 0x18, 0x61, 0x86, 0x30, 0xc3,
    0xc, 0x60,

    /* U+0038 "8" */
    0x7b, 0x3c, 0xf3, 0xcd, 0xec, 0xb3, 0xcf, 0x3c,
    0xf3, 0x78,

    /* U+0039 "9" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x37, 0xc3, 0xf, 0x3c,
    0xf3, 0x78,

    /* U+003A ":" */
    0xc0, 0x0, 0x30,

    /* U+0044 "D" */
    0xfb, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c,
    0xf3, 0xf8,

    /* U+0049 "I" */
    0xff, 0xff, 0xff, 0xc0,

    /* U+004D "M" */
    0xe3, 0xf1, 0xf8, 0xfe, 0xff, 0x7f, 0xbf, 0x57,
    0xab, 0xdd, 0xee, 0xf3, 0x79, 0x3c, 0x98,

    /* U+004F "O" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c,
    0xf3, 0x78
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 57, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 58, .box_w = 2, .box_h = 4, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 2, .adv_w = 122, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 12, .adv_w = 122, .box_w = 4, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 19, .adv_w = 122, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 29, .adv_w = 122, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 39, .adv_w = 122, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 51, .adv_w = 122, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 61, .adv_w = 122, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 71, .adv_w = 122, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 81, .adv_w = 122, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 91, .adv_w = 122, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 101, .adv_w = 58, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 104, .adv_w = 127, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 114, .adv_w = 61, .box_w = 2, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 118, .adv_w = 166, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 127, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0xc, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
    0x16, 0x17, 0x18, 0x19, 0x1a, 0x24, 0x29, 0x2d,
    0x2f
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 48, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 17, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    2, 4,
    3, 4,
    3, 7,
    3, 10,
    4, 2,
    4, 3,
    4, 4,
    4, 5,
    4, 6,
    4, 7,
    4, 8,
    4, 9,
    4, 10,
    4, 11,
    4, 12,
    5, 4,
    5, 7,
    5, 10,
    6, 4,
    6, 7,
    6, 10,
    7, 4,
    7, 7,
    7, 10,
    8, 4,
    8, 7,
    8, 10,
    9, 4,
    9, 7,
    9, 10,
    10, 2,
    10, 4,
    10, 5,
    10, 6,
    10, 7,
    10, 8,
    10, 9,
    10, 10,
    10, 11,
    10, 13,
    11, 4,
    11, 7,
    11, 10,
    12, 4,
    12, 7,
    12, 10
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -17, -5, 3, -1, -12, -12, -19, -13,
    -14, -10, -13, -12, -14, -14, -13, -5,
    -9, -1, -8, 2, -4, -13, 5, -8,
    -9, 2, -4, -6, 3, -2, -16, -8,
    -4, -5, -10, -5, -4, -2, -5, -1,
    -7, 3, -2, -6, 3, -2
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 46,
    .glyph_ids_size = 0
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
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
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
const lv_font_t AlternateGotNo2D_20 = {
#else
lv_font_t AlternateGotNo2D_20 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if ALTERNATEGOTNO2D_20*/

