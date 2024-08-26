/*******************************************************************************
 * Size: 33 px
 * Bpp: 1
 * Opts: --bpp 1 --size 33 --no-compress --font NimbusSanNovTMed Regular.ttf --symbols MENU --format lvgl -o NimbusSanNovT_33.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef NIMBUSSANNOVT_33
#define NIMBUSSANNOVT_33 1
#endif

#if NIMBUSSANNOVT_33

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0045 "E" */
    0xff, 0xff, 0xff, 0xff, 0x80, 0x7, 0x0, 0xe,
    0x0, 0x1c, 0x0, 0x38, 0x0, 0x70, 0x0, 0xe0,
    0x1, 0xc0, 0x3, 0xff, 0xff, 0xff, 0xfe, 0x0,
    0x1c, 0x0, 0x38, 0x0, 0x70, 0x0, 0xe0, 0x1,
    0xc0, 0x3, 0x80, 0x7, 0x0, 0xe, 0x0, 0x1f,
    0xff, 0xff, 0xff, 0x80,

    /* U+004D "M" */
    0xf0, 0x0, 0x3f, 0xe0, 0x1, 0xff, 0x80, 0x7,
    0xff, 0x0, 0x1f, 0xfc, 0x0, 0xff, 0xb0, 0x3,
    0x7e, 0xe0, 0xd, 0xfb, 0x80, 0x77, 0xe6, 0x1,
    0x9f, 0x9c, 0x6, 0x7e, 0x30, 0x39, 0xf8, 0xc0,
    0xc7, 0xe3, 0x83, 0x1f, 0x86, 0x1c, 0x7e, 0x18,
    0x61, 0xf8, 0x71, 0x87, 0xe0, 0xce, 0x1f, 0x83,
    0x30, 0x7e, 0xe, 0xc1, 0xf8, 0x1f, 0x7, 0xe0,
    0x78, 0x1f, 0x81, 0xe0, 0x7e, 0x3, 0x81, 0xc0,

    /* U+004E "N" */
    0xf0, 0x1, 0xfc, 0x0, 0x7f, 0x80, 0x1f, 0xf0,
    0x7, 0xfc, 0x1, 0xfb, 0x80, 0x7e, 0xe0, 0x1f,
    0x9c, 0x7, 0xe7, 0x81, 0xf8, 0xe0, 0x7e, 0x1c,
    0x1f, 0x87, 0x7, 0xe0, 0xe1, 0xf8, 0x1c, 0x7e,
    0x7, 0x1f, 0x80, 0xe7, 0xe0, 0x39, 0xf8, 0x7,
    0x7e, 0x0, 0xff, 0x80, 0x3f, 0xe0, 0x7, 0xf8,
    0x0, 0xfe, 0x0, 0x3c,

    /* U+0055 "U" */
    0xe0, 0x1, 0xf8, 0x0, 0x7e, 0x0, 0x1f, 0x80,
    0x7, 0xe0, 0x1, 0xf8, 0x0, 0x7e, 0x0, 0x1f,
    0x80, 0x7, 0xe0, 0x1, 0xf8, 0x0, 0x7e, 0x0,
    0x1f, 0x80, 0x7, 0xe0, 0x1, 0xf8, 0x0, 0x7e,
    0x0, 0x1f, 0x80, 0x7, 0xe0, 0x1, 0xf8, 0x0,
    0x77, 0x0, 0x19, 0xc0, 0xe, 0x38, 0x7, 0x7,
    0xff, 0x80, 0xff, 0xc0, 0x3, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 308, .box_w = 15, .box_h = 23, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 44, .adv_w = 433, .box_w = 22, .box_h = 23, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 108, .adv_w = 363, .box_w = 18, .box_h = 23, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 160, .adv_w = 354, .box_w = 18, .box_h = 24, .ofs_x = 2, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x8, 0x9, 0x10
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 69, .range_length = 17, .glyph_id_start = 1,
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
const lv_font_t NimbusSanNovT_33 = {
#else
lv_font_t NimbusSanNovT_33 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 24,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if NIMBUSSANNOVT_33*/

