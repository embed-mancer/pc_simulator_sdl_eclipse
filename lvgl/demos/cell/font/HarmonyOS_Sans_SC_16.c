/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --size 16 --no-compress --font HarmonyOS_Sans_SC_Regular.ttf --symbols 电压水温续航0123456789.barvoltgenmpu °CTRV --format lvgl -o HarmonyOS_Sans_SC_16.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef HARMONYOS_SANS_SC_16
#define HARMONYOS_SANS_SC_16 1
#endif

#if HARMONYOS_SANS_SC_16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+002E "." */
    0xf0,

    /* U+0030 "0" */
    0x38, 0x8a, 0x1c, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0xd, 0x11, 0xc0,

    /* U+0031 "1" */
    0x37, 0xd1, 0x11, 0x11, 0x11, 0x11,

    /* U+0032 "2" */
    0x3c, 0xcb, 0x8, 0x10, 0x20, 0xc3, 0xc, 0x30,
    0x61, 0x87, 0xf0,

    /* U+0033 "3" */
    0x3c, 0x66, 0x42, 0x2, 0x6, 0x1c, 0x2, 0x1,
    0x1, 0xc1, 0x62, 0x3c,

    /* U+0034 "4" */
    0x8, 0x18, 0x10, 0x30, 0x20, 0x64, 0x44, 0xc4,
    0xff, 0x4, 0x4, 0x4,

    /* U+0035 "5" */
    0x7e, 0xc1, 0x82, 0x7, 0x88, 0x80, 0x81, 0x2,
    0x85, 0x11, 0xc0,

    /* U+0036 "6" */
    0x8, 0x30, 0xc1, 0x7, 0x88, 0xa0, 0xc1, 0x83,
    0x5, 0x11, 0xc0,

    /* U+0037 "7" */
    0xfe, 0xc, 0x10, 0x60, 0xc1, 0x6, 0x8, 0x10,
    0x60, 0x83, 0x0,

    /* U+0038 "8" */
    0x3c, 0xcd, 0xa, 0x16, 0x67, 0x91, 0xc1, 0x83,
    0x5, 0x11, 0xc0,

    /* U+0039 "9" */
    0x38, 0x8a, 0xc, 0x18, 0x28, 0xcf, 0x6, 0x18,
    0x30, 0xc1, 0x0,

    /* U+0043 "C" */
    0x1e, 0x11, 0x90, 0x50, 0x8, 0x4, 0x2, 0x1,
    0x0, 0x80, 0x20, 0x88, 0xc3, 0xc0,

    /* U+0052 "R" */
    0xf8, 0x84, 0x82, 0x82, 0x82, 0x86, 0xfc, 0x88,
    0x8c, 0x86, 0x82, 0x83,

    /* U+0054 "T" */
    0xff, 0x84, 0x2, 0x1, 0x0, 0x80, 0x40, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x1, 0x0,

    /* U+0056 "V" */
    0xc0, 0x50, 0x36, 0xd, 0x82, 0x21, 0x8c, 0x41,
    0x10, 0x4c, 0x1a, 0x2, 0x80, 0xe0, 0x10,

    /* U+0061 "a" */
    0x3d, 0x8c, 0x8, 0x17, 0xf8, 0x60, 0xc3, 0x7a,

    /* U+0062 "b" */
    0x80, 0x80, 0x80, 0x80, 0xbc, 0xc2, 0x81, 0x81,
    0x81, 0x81, 0x81, 0xc2, 0xbc,

    /* U+0065 "e" */
    0x38, 0x8a, 0xc, 0x1f, 0xf0, 0x20, 0x23, 0x3c,

    /* U+0067 "g" */
    0x3d, 0x43, 0x81, 0x81, 0x81, 0x81, 0x81, 0x43,
    0x3d, 0x1, 0x1, 0xc2, 0x3c,

    /* U+006C "l" */
    0xff, 0xf8,

    /* U+006D "m" */
    0xb9, 0xd9, 0xce, 0x10, 0xc2, 0x18, 0x43, 0x8,
    0x61, 0xc, 0x21, 0x84, 0x20,

    /* U+006E "n" */
    0xbd, 0x8e, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x82,

    /* U+006F "o" */
    0x3c, 0x42, 0x81, 0x81, 0x81, 0x81, 0x81, 0x42,
    0x3c,

    /* U+0070 "p" */
    0xbc, 0xc2, 0x81, 0x81, 0x81, 0x81, 0x81, 0xc2,
    0xbc, 0x80, 0x80, 0x80, 0x80,

    /* U+0072 "r" */
    0xbc, 0x88, 0x88, 0x88, 0x80,

    /* U+0074 "t" */
    0x21, 0x9, 0xf2, 0x10, 0x84, 0x21, 0x8, 0x30,

    /* U+0075 "u" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xe3, 0x7a,

    /* U+0076 "v" */
    0xc3, 0x43, 0x62, 0x26, 0x24, 0x34, 0x1c, 0x18,
    0x18,

    /* U+00B0 "°" */
    0x74, 0x63, 0x17, 0x0,

    /* U+538B "压" */
    0x3f, 0xfc, 0x41, 0x0, 0x82, 0x1, 0x4, 0x2,
    0x8, 0x5, 0xff, 0x88, 0x20, 0x10, 0x58, 0x20,
    0x98, 0xc1, 0x19, 0x2, 0x2, 0xff, 0xf4, 0x0,
    0x0,

    /* U+6C34 "水" */
    0x2, 0x0, 0x8, 0x0, 0x21, 0xbe, 0xcc, 0xb,
    0xe0, 0x6e, 0x1, 0x28, 0x4, 0xb0, 0x32, 0x60,
    0x88, 0x84, 0x23, 0x30, 0x86, 0x82, 0x8, 0x78,
    0x0,

    /* U+6E29 "温" */
    0xc7, 0xf8, 0xc8, 0x10, 0x50, 0x20, 0x3f, 0xcc,
    0x40, 0x8c, 0xff, 0x8, 0x0, 0x0, 0x0, 0x27,
    0xfc, 0x4a, 0x49, 0x94, 0x92, 0x29, 0x24, 0x52,
    0x5b, 0xff, 0xc0,

    /* U+7535 "电" */
    0x4, 0x0, 0x20, 0x3f, 0xf9, 0x8, 0x48, 0x42,
    0x7f, 0xf2, 0x10, 0x90, 0x84, 0x84, 0x27, 0xff,
    0x1, 0x6, 0x8, 0x30, 0x41, 0x83, 0xf8,

    /* U+7EED "续" */
    0x30, 0x40, 0x8f, 0xe6, 0x4, 0x12, 0x10, 0xd7,
    0xfc, 0xcc, 0xa2, 0xa, 0x18, 0xc8, 0xf8, 0x60,
    0x1f, 0xf0, 0x4, 0x3e, 0x2c, 0xc7, 0x1c, 0x10,
    0x0,

    /* U+822A "航" */
    0x10, 0x61, 0xf0, 0x84, 0x5f, 0xdd, 0x0, 0x54,
    0x1, 0x13, 0xcf, 0xc9, 0x11, 0x24, 0x54, 0x91,
    0x52, 0x45, 0x49, 0x51, 0x25, 0x85, 0x16, 0x7c,
    0x70
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 69, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 59, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 13, .adv_w = 146, .box_w = 4, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 19, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 30, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 42, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 54, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 65, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 76, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 87, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 98, .adv_w = 146, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 167, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 164, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 135, .adv_w = 145, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 149, .adv_w = 168, .box_w = 10, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 172, .adv_w = 155, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 140, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 193, .adv_w = 155, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 206, .adv_w = 61, .box_w = 1, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 208, .adv_w = 219, .box_w = 11, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 221, .adv_w = 148, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 229, .adv_w = 151, .box_w = 8, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 155, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 251, .adv_w = 96, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 256, .adv_w = 94, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 264, .adv_w = 149, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 272, .adv_w = 132, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 281, .adv_w = 78, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 285, .adv_w = 256, .box_w = 15, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 310, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 335, .adv_w = 256, .box_w = 15, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 362, .adv_w = 256, .box_w = 13, .box_h = 14, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 385, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 410, .adv_w = 256, .box_w = 14, .box_h = 14, .ofs_x = 1, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0xe, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
    0x16, 0x17, 0x18, 0x19, 0x23, 0x32, 0x34, 0x36,
    0x41, 0x42, 0x45, 0x47, 0x4c, 0x4d, 0x4e, 0x4f,
    0x50, 0x52, 0x54, 0x55, 0x56, 0x90, 0x536b, 0x6c14,
    0x6e09, 0x7515, 0x7ecd, 0x820a
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 33291, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 36, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 2, 3,
    4, 5, 6, 7, 8, 0, 5, 5,
    6, 6, 9, 10, 8, 11, 0, 0,
    0, 0, 0, 0, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 1, 2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 3, 0, 4,
    5, 6, 0, 7, 7, 0, 8, 8,
    7, 0, 8, 9, 10, 11, 0, 0,
    0, 0, 0, 0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 7, -4, 1, 0, 0, 0, 0,
    0, 0, -6, 0, 11, -3, -2, -6,
    0, -3, 0, 0, 0, 0, -8, -28,
    -8, 5, 5, -29, -28, -23, -9, -21,
    -27, -10, -35, -8, 5, 0, -18, -17,
    -10, 0, -10, -10, 0, 0, 0, -21,
    -18, 0, 0, 0, 0, 0, -2, 0,
    -8, 0, -28, -17, -3, 0, 0, -1,
    0, -4, 0, 0, 0, -18, -14, 0,
    0, 0, 0, 0, 1, 0, 0, 0,
    -23, -10, 0, 0, 0, 0, 0, 0,
    0, -26, 0, 0, -9, -11, -8, 0,
    7, 0, 0, 0, 7, 0, -19, -10,
    0, -2, 0, 0, 0, 0, 0, -23,
    0, -27, -10, -4, -4, 0, 0, 0,
    0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 11,
    .right_class_cnt     = 11,
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
    .cmap_num = 1,
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
const lv_font_t HarmonyOS_Sans_SC_16 = {
#else
lv_font_t HarmonyOS_Sans_SC_16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
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



#endif /*#if HARMONYOS_SANS_SC_16*/

