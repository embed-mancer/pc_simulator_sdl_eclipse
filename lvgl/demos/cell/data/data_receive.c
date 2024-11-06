#include "data_receive.h"
#include "../tool/constrant.h"
#include <stdlib.h>
#include <string.h>

void data_task_init() {}

void data_task_add(uint8_t *_msg) {
  uint8_t *msg = malloc(MAX_MSG_LEN);
  if (!msg) {
    memcpy(msg, _msg, 256);
  }
}

void data_task_process(uint8_t *msg) {
  uint8_t code = msg[2];
  switch (code) {}
}
