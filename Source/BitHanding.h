#pragma once

#include"QInt.h"
//lấy ra bit thứ index
bool GetBit(int &a, int index);
//bật bit tại vị trí index (bit lên bit 1)
bool TurnOnBit(int &a, int index);
//tắt bit tại vị trí index (b xuống bit 0)
bool TurnOffBit(int &a, int index);
