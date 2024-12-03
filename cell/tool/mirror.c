#include "mirror.h"
#include "lvgl/lvgl.h"
#include "../cell.h"

void mirror_horizontal(uint8_t *img_data, uint32_t width, uint32_t height, uint32_t bytes_per_pixel) {
    for (uint32_t y = 0; y < height; y++) {
        uint8_t *row_start = img_data + y * width * bytes_per_pixel;
        uint8_t *left = row_start;
        uint8_t *right = row_start + (width - 1) * bytes_per_pixel;

        while (left < right) {
            // Swap the pixels
            for (uint32_t b = 0; b < bytes_per_pixel; b++) {
                uint8_t temp = left[b];
                left[b] = right[b];
                right[b] = temp;
            }

            // Move pointers
            left += bytes_per_pixel;
            right -= bytes_per_pixel;
        }
    }
}


static void print_img_data(const lv_img_decoder_dsc_t *dsc) {
  uint32_t height = dsc->header.h;
  uint32_t width = dsc->header.w;
  uint8_t bytes_per_pixel;

  // 根据颜色格式设置每像素字节数
  if (dsc->header.cf == LV_IMG_CF_TRUE_COLOR) {
    bytes_per_pixel = LV_COLOR_DEPTH / 8;
  } else if (dsc->header.cf == LV_IMG_CF_TRUE_COLOR_ALPHA) {
    bytes_per_pixel = 4;  // 通常为 ARGB8888
  } else {
    printf("Unsupported color format\n");
    return;
  }

  printf("Image data:\n");
  for (uint32_t y = 0; y < height; y++) {
    for (uint32_t x = 0; x < width; x++) {
      const uint8_t *pixel_ptr =
          dsc->img_data + (y * width + x) * bytes_per_pixel;

      if (bytes_per_pixel == 2) {  // 16 位色（RGB565）
        uint16_t pixel = *(const uint16_t *)pixel_ptr;
        printf("0x%04X ", pixel);
      } else if (bytes_per_pixel == 4) {  // 32 位色（ARGB8888）
        uint32_t pixel = *(const uint32_t *)pixel_ptr;
        printf("0x%08X ", pixel);
      }

      if (x % 16 == 15) {  // 每行打印 16 个像素
        printf("\n");
      }
    }
    printf("\n");
  }
}

void mirror() {
  const char *img_src = RES_PRFIX "1.png";
  // 初始化解码描述符
  lv_img_decoder_dsc_t dsc;
  // lv_memzero(&dsc, sizeof(lv_img_decoder_dsc_t));

  // 调用解码器
  lv_res_t res = lv_img_decoder_open(&dsc, img_src, lv_color_black(), 0);
  if (res != LV_RES_OK) {
    printf("Failed to decode image\n");
    return;
  }

  // 获取图像数据
  uint8_t *img_data = dsc.img_data;
  uint32_t width = dsc.header.w;
  uint32_t height = dsc.header.h;
  lv_img_cf_t color_format = dsc.header.cf;

  printf("Image width: %u, height: %u, color format: %d\n", width, height,
         color_format);

  // 打印图像数据
  if (img_data) {
    // print_img_data(&dsc);
  }

  // 创建一个新的图像描述符并复制数据
  uint32_t data_size = width * height * (LV_COLOR_DEPTH / 8);
  uint8_t *img_data_copy = lv_mem_alloc(data_size);
  if (!img_data_copy) {
    printf("Failed to allocate memory for image data copy\n");
    lv_img_decoder_close(&dsc);
    return;
  }
  mirror_horizontal(img_data, width, height, 4);
  memcpy(img_data_copy, img_data, data_size);

  // 定义图像描述符
  static lv_img_dsc_t my_img;
  my_img.header.always_zero = 0;
  my_img.header.w = width;
  my_img.header.h = height;
  my_img.header.cf = color_format;
  my_img.data_size = data_size;
  my_img.data = img_data_copy;

  // 显示图像
  lv_obj_t *img_obj = lv_img_create(main_window_get());
  lv_img_set_src(img_obj, &my_img);
  // lv_obj_align(img_obj, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_pos(img_obj, 500, 200);

  // 释放解码器资源
  lv_img_decoder_close(&dsc);
  // 注意：img_data_copy 的释放应在图像控件销毁后进行
}
