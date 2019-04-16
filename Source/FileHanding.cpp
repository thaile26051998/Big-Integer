#include "FileHanding.h"
#include "QInt.h"
#include <algorithm>

//Tách các phép tính thành các toán tử và toán hạng
vector<string> SplitString(string str)
{
	char* s = _strdup(str.c_str());
	char* temp = nullptr;
	vector<string> res;
	temp = strtok(s, " ");
	if (temp) res.push_back((string)temp);
	while (temp = strtok(nullptr, " ")) res.push_back((string)temp);
	delete[]s;
	return res;
}

//Đọc file, thành danh sách các phép tính
vector<string> ReadFile(ifstream& fi)
{
	vector<string> res;
	string tmp;
	while (!fi.eof())
	{
		getline(fi, tmp);
		res.push_back(tmp);
	}
	return res;
}

//Ghi kết quả
void WriteFile(ofstream& fo,const vector<string>& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		fo << str[i] << endl;
	}
}

//Xử lí mỗi dòng phép tính được yêu cầu
string Handing(vector<string> str)
{
	if (str.size() == 4)
	{
		if (str[2] != ">>" && str[2] != "<<")
		{
			QInt int1(str[1], str[0]);
			QInt int2(str[3], str[0]);
			if (str[2] == "+")
			{
				QInt res = int1 + int2;
				return res.WriteQInt(str[0]);
			}
			if (str[2] == "-")
			{
				QInt res = int1 - int2;
				return res.WriteQInt(str[0]);
			}
			if (str[2] == "*")
			{
				QInt res = int1 * int2;
				return res.WriteQInt(str[0]);
			}
			if (str[2] == "/")
			{
				QInt res = int1 / int2;
				return res.WriteQInt(str[0]);
			}
			if (str[2] == "|")
			{
				QInt res = int1 | int2;
				return res.WriteQInt(str[0]);
			}
			if (str[2] == "^")
			{
				QInt res = int1 ^ int2;
				return res.WriteQInt(str[0]);
			}
			if (str[2] == "&")
			{
				QInt res = int1 & int2;
				return res.WriteQInt(str[0]);
			}
		}
		else
		{
			QInt int0(str[1], str[0]);
			int n = atoi(str[3].c_str());
			if (str[2] == ">>")
			{
				QInt res = int0 >> n;
				return res.WriteQInt(str[0]);
			}
			if (str[2] == "<<")
			{
				QInt res = int0 << n;
				return res.WriteQInt(str[0]);
			}
		}
	}
	if (str.size() == 3)
	{
		QInt int0(str[2], str[0]);
		if (str[1] == "2")
		{
			return int0.WriteQInt(str[1]);
		}
		if (str[1] == "16")
		{
			return int0.WriteQInt(str[1]);
		}
		if (str[1] == "10")
		{
			return int0.WriteQInt(str[1]);
		}
		if (str[1] == "rol")
		{
			return int0.rol(1).WriteQInt(str[0]);
		}
		if (str[1] == "ror")
		{
			return int0.ror(1).WriteQInt(str[0]);
		}
		if (str[1] == "~")
		{
			return (~int0).WriteQInt(str[0]);
		}
	}
	return "";
}

// Xử lí File
void HandingFile(string FileIn, string FileOut)
{
	ifstream fi;
	ofstream fo;
	fi.open(FileIn, ios::in);
	if (!fi)
	{
		cout << "Khong tim thay file";
		return;
	}
	vector<string> tmp = ReadFile(fi);
	vector<string> res;
	fi.close();
	for (int i = 0; i < tmp.size(); i++)
	{
		string s = Handing(SplitString(tmp[i]));
		res.push_back(s);
	}
	fo.open(FileOut, ios::out);
	WriteFile(fo,res);
	fo.close();
}