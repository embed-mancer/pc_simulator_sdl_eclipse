#ifndef DATA_RECEIVE_H
#define DATA_RECEIVE_H

#include "lvgl/lvgl.h"

void DataTaskInit();
void DataTaskAdd(uint8_t *msg);
void DataTaskProcess(uint8_t *msg);

#endif /* ifndef DATA_RECEIVE_H */
