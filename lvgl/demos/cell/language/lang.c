#include "lang.h"
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

#include "../tool/log.h"
#include "../tool/enums.h"

static language_e default_language = LANGUAGE_CHINESE;

char* languages[TEXT_ID_COUNT][LANGUAGE_COUNT] = {
    [TEXT_ID_VEHICLE_SETTINGS] = {"车辆设置", "Vehicle settings"},
    [TEXT_ID_VEHICLE_INFO]     = {"车辆信息", "Vehicle info"},
    [TEXT_ID_QUICK_SHIFT]      = {"快速换挡", "Quick shift"},
    [TEXT_ID_UPSHIFT]          = {"升档提示", "Upshift"},

    [TEXT_ID_BASIC_INFO]       = {"基本信息", "Basic info"},
    [TEXT_ID_ODO]              = {"ODO信息", "ODO info"},
    [TEXT_ID_TRIP]             = {"TRIP信息", "TRIP info"},
    [TEXT_ID_FAULT_INFO]       = {"故障信息", "Fault info"},
    [TEXT_ID_MAINTAIN_MILEAGE] = {"剩余保养里程",
                                  "Remaining maintenance mileage"},

    [TEXT_ID_PHONE]        = {"电话", "Phone"},
    [TEXT_ID_CONTACTS]     = {"通讯录", "Contacts"},
    [TEXT_ID_RECENT_CALLS] = {"最近通话", "Recent calls"},

    [TEXT_ID_MUSIC] = {"音乐", "Music"},

    [TEXT_ID_SETTINGS]          = {"设置", "Settings"},
    [TEXT_ID_DEVICE_CONNECTION] = {"设备连接", "Device connection"},
    [TEXT_ID_OPTIONAL_INFO_1]   = {"可选信息1", "Optional info 1"},
    [TEXT_ID_OPTIONAL_INFO_2]   = {"可选信息2", "Optional info 2"},
    [TEXT_ID_AUTO_BRIGHTNESS]   = {"自动亮度", "Auto brightness"},
    [TEXT_ID_UNIT_SETTINGS]     = {"单位设置", "Unit settings"},
    [TEXT_ID_TIME_SETTINGS]     = {"时间设置", "Time settings"},
    [TEXT_ID_LANGUAGE_SETTINGS] = {"语言设置", "Language settings"},

    [TEXT_ID_OPEN]  = {"打开", "Open"},
    [TEXT_ID_CLOSE] = {"关闭", "Close"},
};

const char* get_translation(text_id_t text_id, language_e language) {
  if (text_id < 0 || text_id >= TEXT_ID_COUNT) {
    LOG_ERROR("Error: Invalid TextID: %d\n", text_id);
    return NULL;
  }
  if (language < 0 || language >= LANGUAGE_COUNT) {
    LOG_ERROR("Error: Invalid Language: %d\n", language);
    return NULL;
  }
  if (languages[text_id][language] == NULL) {
    LOG_ERROR("Error: Translation not available for TextID %d in Language %d\n",
              text_id, language);
    return NULL;
  }

  return languages[text_id][language];
}

const char* lang_text(text_id_t text_id) {
  return get_translation(text_id, default_language);
}
