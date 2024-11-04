#include "data_receive.h"
#include "../tool/constrant.h"
#include <stdlib.h>
#include <string.h>

void DataTaskInit() {
  
}

void DataTaskAdd(uint8_t *_msg) {
  uint8_t *msg = malloc(kMaxMsgLen);
  if (!msg) {
    memcpy(msg, _msg, 256);
  }
}

void DataTaskProcess(uint8_t *msg) {
  uint8_t code = msg[2];
  switch (code) {

  }
}
