/*******************************************************************************
 * Size: 18 px
 * Bpp: 1
 * Opts: --bpp 1 --size 18 --no-compress --font SourceHanSansCN-Regular_0.ttf --symbols EFHCGAR --format lvgl -o SourceHanSansCN_18.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef SOURCEHANSANSCN_18
#define SOURCEHANSANSCN_18 1
#endif

#if SOURCEHANSANSCN_18

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0041 "A" */
    0xe, 0x1, 0x40, 0x28, 0xd, 0x81, 0xb0, 0x22,
    0xc, 0x61, 0x8c, 0x3f, 0x8c, 0x19, 0x83, 0x20,
    0x2c, 0x6,

    /* U+0043 "C" */
    0x1f, 0x8c, 0x36, 0x1, 0x80, 0xc0, 0x30, 0xc,
    0x3, 0x0, 0xc0, 0x18, 0x6, 0x0, 0xc3, 0x1f,
    0x80,

    /* U+0045 "E" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0xff,

    /* U+0046 "F" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0047 "G" */
    0x1f, 0x8c, 0x26, 0x1, 0x80, 0xc0, 0x30, 0xc,
    0x3f, 0x3, 0xc0, 0xf0, 0x36, 0xc, 0xc3, 0x1f,
    0x80,

    /* U+0048 "H" */
    0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0, 0xf0, 0x3f,
    0xff, 0x3, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0,
    0xc0,

    /* U+0052 "R" */
    0xfe, 0x61, 0xb0, 0x78, 0x3c, 0x1e, 0x1b, 0xf9,
    0x98, 0xc6, 0x63, 0x30, 0xd8, 0x7c, 0x18
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 175, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 18, .adv_w = 184, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 35, .adv_w = 170, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 48, .adv_w = 159, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 61, .adv_w = 198, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 78, .adv_w = 210, .box_w = 10, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 95, .adv_w = 183, .box_w = 9, .box_h = 13, .ofs_x = 2, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x2, 0x4, 0x5, 0x6, 0x7, 0x11
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 65, .range_length = 18, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 7, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 1, 2, 0, 3, 4, 0, 4
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 1, 2, 0, 0, 2, 0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    -2, -3, 0, -9, -12, -3, -1, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 4,
    .right_class_cnt     = 2,
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
const lv_font_t SourceHanSansCN_18 = {
#else
lv_font_t SourceHanSansCN_18 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 13,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
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



#endif /*#if SOURCEHANSANSCN_18*/

