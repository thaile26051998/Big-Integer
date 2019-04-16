#include"BitHanding.h"
//lấy ra bit thứ index
bool GetBit(int &a, int index) {
	//kiểm tra
	if (index < 0 || index > NUM_BIT)
		return false;
	return (a >> index) & 1;
}

//bật bit tại vị trí index (bit lên bit 1)
bool TurnOnBit(int &a, int index) {
	//kiểm tra
	if (index < 0 || index > NUM_BIT)
		return false;
	a |= (1 << index);
	return true;
}

//tắt bit tại vị trí index (bit xuống bit 0)
bool TurnOffBit(int &a, int index) {
	//kiểm tra
	if (index < 0 || index > NUM_BIT)
		return false;
	a &= ~(1 << index);
	return true;
}

