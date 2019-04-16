#pragma once
#ifndef _FILE_HANDING_
#define _FILE_HANDING_
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;
//Tách các phép tính thành các toán tử và toán hạng
vector<string> SplitString(string);
//Đọc file, thành danh sách các phép tính
vector<string> ReadFile(ifstream&);
//Ghi kết quả
void WriteFile(ofstream&,const vector<string>&);
//Xử lí mỗi dòng phép tính được yêu cầu
string Handing(vector<string>);
// Xử lí File
void HandingFile(string, string);
#endif _FILE_HANDING_