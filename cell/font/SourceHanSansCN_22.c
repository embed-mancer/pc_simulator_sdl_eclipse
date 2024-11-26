/*******************************************************************************
 * Size: 21 px
 * Bpp: 1
 * Opts: --bpp 1 --size 21 --no-compress --font SourceHanSansCN-Regular_0.ttf --symbols km/h --format lvgl -o SourceHanSansCN_22.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef SOURCEHANSANSCN_22
#define SOURCEHANSANSCN_22 1
#endif

#if SOURCEHANSANSCN_22

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+002F "/" */
    0x3, 0x2, 0x2, 0x6, 0x6, 0x4, 0x4, 0xc,
    0x8, 0x8, 0x18, 0x10, 0x10, 0x30, 0x30, 0x20,
    0x20, 0x60, 0x40, 0x40, 0xc0,

    /* U+0068 "h" */
    0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0xf3, 0xcd,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf,
    0x7, 0x83, 0xc1, 0x80,

    /* U+006B "k" */
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30, 0x6c,
    0x33, 0x18, 0xcc, 0x37, 0xd, 0xc3, 0xf0, 0xe6,
    0x31, 0x8c, 0x33, 0x6, 0xc1, 0x80,

    /* U+006D "m" */
    0xdf, 0x3c, 0xe3, 0xc6, 0xc1, 0x83, 0xc1, 0x83,
    0xc1, 0x83, 0xc1, 0x83, 0xc1, 0x83, 0xc1, 0x83,
    0xc1, 0x83, 0xc1, 0x83, 0xc1, 0x83, 0xc1, 0x83
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 132, .box_w = 8, .box_h = 21, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 21, .adv_w = 204, .box_w = 9, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 41, .adv_w = 185, .box_w = 10, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 63, .adv_w = 311, .box_w = 16, .box_h = 12, .ofs_x = 2, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x39, 0x3c, 0x3e
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 47, .range_length = 63, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 4, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
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
    .kern_dsc = NULL,
    .kern_scale = 0,
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
const lv_font_t SourceHanSansCN_22 = {
#else
lv_font_t SourceHanSansCN_22 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 21,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if SOURCEHANSANSCN_22*/

