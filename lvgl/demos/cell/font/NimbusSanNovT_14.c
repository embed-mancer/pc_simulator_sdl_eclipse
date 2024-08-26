/*******************************************************************************
 * Size: 12 px
 * Bpp: 1
 * Opts: --bpp 1 --size 12 --no-compress --font NimbusSanNovTMed Regular.ttf --symbols QWERTYUIOPASDFGHJKLZXCVBNM  --format lvgl -o NimbusSanNovT_14.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef NIMBUSSANNOVT_14
#define NIMBUSSANNOVT_14 1
#endif

#if NIMBUSSANNOVT_14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0041 "A" */
    0x18, 0x18, 0x28, 0x24, 0x64, 0x7e, 0x42, 0x82,

    /* U+0042 "B" */
    0xfa, 0x18, 0x7e, 0x86, 0x18, 0x7e,

    /* U+0043 "C" */
    0x3c, 0x8e, 0xc, 0x8, 0x10, 0x51, 0x9e,

    /* U+0044 "D" */
    0xf9, 0xa, 0xc, 0x18, 0x30, 0x61, 0x7c,

    /* U+0045 "E" */
    0xfe, 0x8, 0x3e, 0x82, 0x8, 0x3f,

    /* U+0046 "F" */
    0xfc, 0x21, 0xf8, 0x42, 0x10,

    /* U+0047 "G" */
    0x3c, 0x8e, 0x4, 0x78, 0x30, 0x51, 0x9d,

    /* U+0048 "H" */
    0x86, 0x18, 0x7f, 0x86, 0x18, 0x61,

    /* U+0049 "I" */
    0xff,

    /* U+004A "J" */
    0x8, 0x42, 0x10, 0xc6, 0x2e,

    /* U+004B "K" */
    0x85, 0x12, 0xc7, 0xd, 0x13, 0x22, 0x42,

    /* U+004C "L" */
    0x84, 0x21, 0x8, 0x42, 0x1f,

    /* U+004D "M" */
    0xc3, 0xc3, 0xc3, 0xa5, 0xa5, 0x99, 0x99, 0x99,

    /* U+004E "N" */
    0x87, 0x1a, 0x69, 0x96, 0x58, 0xe1,

    /* U+004F "O" */
    0x3c, 0x42, 0x81, 0x81, 0x81, 0x81, 0x42, 0x3c,

    /* U+0050 "P" */
    0xfa, 0x18, 0x61, 0xfa, 0x8, 0x20,

    /* U+0051 "Q" */
    0x3c, 0x42, 0x81, 0x81, 0x81, 0x81, 0x46, 0x3f,
    0x0,

    /* U+0052 "R" */
    0xfa, 0x18, 0x61, 0xfa, 0x18, 0x61,

    /* U+0053 "S" */
    0x3c, 0x8d, 0x1, 0x80, 0xe8, 0x50, 0x9e,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8,

    /* U+0055 "U" */
    0x86, 0x18, 0x61, 0x86, 0x1c, 0x5e,

    /* U+0056 "V" */
    0x82, 0x89, 0x12, 0x22, 0x85, 0xa, 0x8,

    /* U+0057 "W" */
    0x8c, 0x53, 0x14, 0xc5, 0x2a, 0x52, 0x8c, 0xa3,
    0x18, 0x84,

    /* U+0058 "X" */
    0x44, 0x88, 0xa0, 0x83, 0x85, 0x11, 0x63,

    /* U+0059 "Y" */
    0x82, 0x88, 0xa1, 0x41, 0x2, 0x4, 0x8,

    /* U+005A "Z" */
    0xfe, 0x8, 0x20, 0x82, 0xc, 0x30, 0x7f
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 48, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 122, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 9, .adv_w = 124, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 15, .adv_w = 130, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 22, .adv_w = 129, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 29, .adv_w = 112, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 35, .adv_w = 103, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 40, .adv_w = 138, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 131, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 53, .adv_w = 46, .box_w = 1, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 54, .adv_w = 90, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 59, .adv_w = 119, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 66, .adv_w = 103, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 71, .adv_w = 158, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 79, .adv_w = 132, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 139, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 93, .adv_w = 116, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 99, .adv_w = 137, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 108, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 114, .adv_w = 115, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 121, .adv_w = 109, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 128, .adv_w = 129, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 134, .adv_w = 113, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 166, .box_w = 10, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 151, .adv_w = 111, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 158, .adv_w = 112, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 165, .adv_w = 112, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 1, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 65, .range_length = 26, .glyph_id_start = 2,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    2, 4,
    2, 8,
    2, 16,
    2, 18,
    2, 21,
    2, 22,
    2, 23,
    2, 24,
    2, 26,
    3, 2,
    3, 16,
    3, 23,
    3, 24,
    3, 26,
    4, 2,
    4, 9,
    4, 12,
    4, 16,
    5, 2,
    5, 11,
    5, 21,
    5, 23,
    5, 24,
    5, 25,
    5, 26,
    7, 2,
    7, 11,
    7, 16,
    8, 2,
    8, 21,
    8, 23,
    8, 24,
    8, 26,
    11, 2,
    12, 4,
    12, 8,
    12, 16,
    12, 20,
    12, 21,
    13, 2,
    13, 4,
    13, 8,
    13, 16,
    13, 20,
    13, 21,
    13, 22,
    13, 23,
    13, 24,
    13, 26,
    15, 2,
    15, 4,
    15, 8,
    15, 16,
    16, 2,
    16, 21,
    16, 23,
    16, 24,
    16, 25,
    16, 26,
    17, 2,
    17, 11,
    19, 4,
    19, 8,
    19, 16,
    19, 21,
    19, 22,
    19, 23,
    19, 24,
    19, 26,
    20, 2,
    20, 21,
    20, 23,
    20, 24,
    20, 26,
    21, 2,
    21, 4,
    21, 8,
    21, 11,
    21, 16,
    21, 20,
    21, 23,
    21, 24,
    21, 26,
    22, 2,
    23, 2,
    23, 4,
    23, 8,
    23, 16,
    23, 20,
    23, 21,
    24, 2,
    24, 4,
    24, 8,
    24, 16,
    24, 20,
    24, 21,
    25, 4,
    25, 16,
    25, 18,
    26, 2,
    26, 4,
    26, 8,
    26, 16,
    26, 20,
    26, 21
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -5, -5, -5, -6, -15, -4, -9, -7,
    -14, -2, 0, -3, -1, -4, -3, 0,
    0, 0, -5, 1, -5, -4, -2, -5,
    -7, -10, -7, -2, 2, -5, -4, -2,
    -7, -3, -6, -7, -6, -2, 6, 6,
    -5, -5, -5, 1, -16, -3, -14, -9,
    -18, 0, 0, 0, 0, -5, -6, -5,
    -2, -5, -8, -11, -11, -3, -3, -3,
    -3, -1, -4, -3, -5, -1, -3, -4,
    -2, -5, -15, -7, -7, -16, -6, 0,
    6, 6, 8, -4, -9, -5, -5, -5,
    -2, 6, -7, -2, -2, -2, 0, 6,
    -5, -5, -5, -14, -8, -8, -8, -3,
    8
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 105,
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
    .cmap_num = 2,
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
const lv_font_t NimbusSanNovT_14 = {
#else
lv_font_t NimbusSanNovT_14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 9,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
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



#endif /*#if NIMBUSSANNOVT_14*/

