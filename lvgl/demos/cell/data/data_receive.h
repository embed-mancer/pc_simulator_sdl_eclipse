#ifndef DATA_RECEIVE_H
#define DATA_RECEIVE_H

#include "lvgl/lvgl.h"

void data_task_init();
void data_task_add(uint8_t *msg);
void data_task_process(uint8_t *msg);

#endif /* ifndef DATA_RECEIVE_H */
