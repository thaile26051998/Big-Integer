#pragma once
#include"QInt.h"
using namespace std;

//Lấy ra số dư khi chia 1 số ở hệ 10 cho 2
int GetSurplus(string buff);
//chuyển kí số từ hệ 16 sang hệ 2
string HexToBinChar(char c);
//chuyển kí số từ hệ 2 sang hệ 16
char BinToHexChar(string num);
//chuyển chuỗi ở hệ 16 sang hệ 2
string HexToBinString(string buff);
//chuyển chuỗi ở hệ 2 sang hệ 16
string BinToHexString(string buff);
//chuyển ký tự sang số
int stringToNum(char c);
//chuyển số sang ký tự
char numToString(int n);
//chuẩn hóa chuỗi
void chuanHoa(string &a, string &b);
//tổng 2 chuỗi 
string sum(string a, string b);
//nhân 1 số nhỏ với số lớn
string nhanNho(char a, string b);
//nhân 2 số lớn
string nhan(string a, string b);
//tính lũy thừa
string luythua(string a, int n);
//chia số ở hệ 10
string DecDevide(string buff);
//cộng 1 để thành số bù 2
vector<bool> CongBit1(vector<bool> res);
//trừ để về số bù 1
vector<bool> TruBit1(vector<bool> res);
//đổi sang số bù 2
vector<bool> SoBu2(vector<bool> res);
//chuyển số bù 2 sang số lượng dấu
vector<bool> SoBu2SangSoLuongDau(vector<bool> res);
//chuyển từ hệ 10 sang hệ 2
vector<bool> DecToBinString(string buff);
//chuyển từ hệ 2 sang hệ 10
string BinToDecString(vector<bool> x);