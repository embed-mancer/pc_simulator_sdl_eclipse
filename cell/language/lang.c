#include "lang.h"
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

#include "../tool/log.h"
#include "../tool/enums.h"

static language_e default_language = LANGUAGE_CHINESE;

static const char* languages[TEXT_ID_COUNT][LANGUAGE_COUNT] = {
    [TEXT_ID_DISPLAY]   = {"显示模式", "Display"},
    [TEXT_ID_BACKLIGHT] = {"背光设置", "Backlight"},
    [TEXT_ID_BLUETOOTH] = {"蓝牙连接", "Bluetooth"},
    [TEXT_ID_CLOCK]     = {"时钟设置", "Clock"},
    [TEXT_ID_UNIT]      = {"单位设置", "Unit"},
    [TEXT_ID_LANGUAGE]  = {"语言设置", "Language"},
    [TEXT_ID_VEHICLE]   = {"车辆信息", "Vehicle info"},
    [TEXT_ID_FAULT]     = {"故障信息", "Fault info"},
    [TEXT_ID_MOBILE]    = {"手机互联", "Mobile"},

    [TEXT_ID_BASIC]      = {"基本信息", "Basic info"},
    [TEXT_ID_ODO]        = {"ODO信息", "ODO info"},
    [TEXT_ID_TRIP]       = {"TRIP信息", "TRIP info"},
    [TEXT_ID_FAULT_INFO] = {"故障内容", "Fault info"},
    [TEXT_ID_MAINTAIN]   = {"剩余保养里程", "Maintain"},

    [TEXT_ID_DAY]   = {"日间", "Day"},
    [TEXT_ID_NIGHT] = {"夜间", "Night"},
    [TEXT_ID_AUTO]  = {"自动", "Auto"},

    [TEXT_ID_METRIC]   = {"公制", "Metric"},
    [TEXT_ID_IMPERIAL] = {"英制", "Imperial"},

    [TEXT_ID_BT_NAME]    = {"蓝牙名称:", "BT Name:"},
    [TEXT_ID_BT_CONNECT] = {"蓝牙连接:", "BT Connection:"},
    [TEXT_ID_BT_SYNC]    = {"同步联系人:", "Sync:"},
    [TEXT_ID_BT_OPEN]    = {"[开]", "[Open]"},
    [TEXT_ID_BT_CLOSE]   = {"[关]", "[Close]"},

    [TEXT_ID_VOLTAGE]     = {"电压", "Voltage"},
    [TEXT_ID_RANGE]       = {"续航", "Range"},
    [TEXT_ID_TEMPERATURE] = {"水温", "Temperature"},

    [TEXT_ID_OPEN]  = {"打开", "Open"},
    [TEXT_ID_CLOSE] = {"关闭", "Close"},

    [TEXT_ID_FAULT_CURRENT] = {"当前故障:", "Current faults:"},
    [TEXT_ID_FAULT_HISTORY] = {"历史故障:", "History faults:"},
    [TEXT_ID_FAULT_OS]      = {"OS版本号:", "OS version:"},
    [TEXT_ID_FAULT_MCU]     = {"MCU版本号:", "MCU version:"},

    [TEXT_ID_MAIN_TRIP]      = {"小计里程", "Trip"},
    [TEXT_ID_MAIN_AVG_SPEED] = {"平均车速", "Avg speed"},
    [TEXT_ID_MAIN_RIDE_TIME] = {"骑行时间", "Ride time"},
    [TEXT_ID_MAIN_BATTERY]   = {"电池电压", "Voltage"},

    [TEXT_ID_SETTINGS] = {"设置", "Settings"},
};

static const char* get_translation(text_id_t text_id, language_e language) {
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

void lang_set(language_e e) {
  if (e >= 0 && e < LANGUAGE_COUNT) {
    default_language = e;
  } else {
    LOG_ERROR("Error: Invalid Language: %d\n", e);
  }
}
