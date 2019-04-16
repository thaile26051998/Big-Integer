#pragma once
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<cstdint>
#include"BitHanding.h"
#include"StringHanding.h"
using namespace std;
const int NUM_BIT = 32;
#define MAX_LENGTH  4

class QInt {
private:
	int data[MAX_LENGTH];
public:
	//khởi tạo mặc định
	QInt();
	//Khởi tạo từ vector bool
	QInt(vector<bool>);
	//Khởi tạo có kiểu
	QInt(string, string);
	//Khởi tạo hệ 10
	QInt(string);
	//khởi tạo giá trị cho data[index]
	void InputData(int index, int buff);
	//kiểm tra xem mảng có toàn giá trị 0 hay không
	bool IsArrayZero();
	//lấy bit thứ index trong mảng data[]
	bool GetBitDataInt(int index);
	//gán bit thứ index trong mảng data[] bằng giá trị bit
	bool SetBitDataInt(int index, bool bit);
	//operator =
	QInt& operator=(const QInt& src);
	//operator &
	QInt operator &(QInt buff);
	//operator |
	QInt operator |(QInt buff);
	//operator ^
	QInt operator ^(QInt buff);
	//operator ~
	QInt operator ~();
	//dịch trái num bit
	QInt operator <<(int num);
	//dịch phải num bit
	QInt operator >>(int num);
	//Đổi dấu QInt
	QInt operator-();
	//cộng 2 QInt
	QInt operator + (QInt buff);
	//trừ 2 QInt
	QInt operator - (QInt buff);
	//chuyển từ QInt sang hệ 2
	string QIntToBin();
	//chuyển từ QInt sang hệ 10
	string QIntToDec();
	//chuyển từ QInt sang hệ 16
	string QIntToHex();
	//chuyển từ QInt sang các hệ cơ số 2, 10, 16
	string WriteQInt(string base);
	//xoay trái
	QInt rol(int n);
	//xoay phải
	QInt ror(int n);
};

//nhân 2 QInt
QInt operator * (QInt q, QInt m);
//chia 2 QInt
QInt operator / (QInt q, QInt m);

