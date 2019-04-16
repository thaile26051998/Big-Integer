#include"QInt.h"

//khởi tạo mặc định
QInt::QInt() {
	for (int i = 0; i < MAX_LENGTH; i++)
		data[i] = 0;
}

//khởi tạo từ vector bool
QInt::QInt(vector<bool> bin)
{
	for (int i = 127; i >=0; i--)
	{
		SetBitDataInt(127 - i, bin[i]);
	}
}

//khởi tạo từ kiểu 10
QInt::QInt(string s)
{
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		data[i] = 0;
	}
	vector<bool> bin = DecToBinString(s);
	*this = QInt(bin);
}

//khởi tạo có kiểu
QInt::QInt(string num, string type)
{
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		data[i] = 0;
	}
	if (type == "10")
	{
		*this = QInt(num);
	}
	else if (type == "16")
	{
		string temp = HexToBinString(num);
		for (int i = temp.length() - 1; i >= 0; i--)
		{
			SetBitDataInt(127 - i, temp[i] - 48);
		}
	}
	else if (type == "2")
	{
		int j = 0;
		while (num.length() < 128)
		{
			num = '0' + num;
			j++;
		}
		for (int i = num.length() - 1; i >= 0; i--)
		{
			SetBitDataInt(127 - i, num[i] - 48);
		}
	}
}

//khởi tạo giá trị cho data[index]
void QInt::InputData(int index, int buff) {
	if (index == MAX_LENGTH || index < 0)
		return;
	this->data[index] = buff;
}

//kiểm tra xem mảng có toàn giá trị 0 hay không
bool QInt::IsArrayZero() {
	for (int i = 0; i < MAX_LENGTH; i++)
		if (data[i] == 0)
			return false;
	return true;
}

//lấy bit thứ index trong mảng data[]
bool QInt::GetBitDataInt(int index) {
	//kiểm tra
	if (index < 0 || index > NUM_BIT*MAX_LENGTH - 1)
		return false;
	else {
		//vị trí byte để get bit
		//tương đương vị trí trong mảng data[]
		int BytePos = MAX_LENGTH - 1;
		while (index - NUM_BIT >= 0) {
			index = index - NUM_BIT;
			BytePos--;
		}
		return GetBit(data[BytePos], index);
	}
}

//gán bit thứ index trong data[] bằng giá trị bit
bool QInt::SetBitDataInt(int index, bool bit) {
	//kiểm tra
	if (index < 0 || index > NUM_BIT*MAX_LENGTH - 1)
		return false;
	else {
		//vị trí byte để get bit
		//tương đương vị trí trong mảng data[]
		int BytePos = MAX_LENGTH - 1;
		while (index - NUM_BIT >= 0) {
			index = index - NUM_BIT;
			BytePos--;
		}
		if (bit == 1)
			TurnOnBit(data[BytePos], index);
		else
			TurnOffBit(data[BytePos], index);
		return true;
	}
}

//operator =
QInt& QInt::operator=(const QInt& src)
{
	for (int i = 0; i < MAX_LENGTH; i++)
	{
		data[i] = src.data[i];
	}
	return *this;
}

//operator &
QInt QInt::operator &(QInt buff) {
	QInt res;
	for (int i = 0; i < MAX_LENGTH; i++)
		res.data[i] = (*this).data[i] & buff.data[i];
	return res;
}

//operator |
QInt QInt::operator |(QInt buff) {
	QInt res;
	for (int i = 0; i < MAX_LENGTH; i++)
		res.data[i] = (*this).data[i] | buff.data[i];
	return res;
}

//operator ^
QInt QInt::operator ^(QInt buff) {
	QInt res;
	for (int i = 0; i < MAX_LENGTH; i++)
		res.data[i] = (*this).data[i] ^ buff.data[i];
	return res;
}

//operator ~
QInt QInt::operator ~() {
	QInt res;
	for (int i = 0; i < MAX_LENGTH; i++)
		res.data[i] = ~(*this).data[i];
	return res;
}

//dịch trái num bit
QInt QInt::operator <<(int num){
	int size = MAX_LENGTH * NUM_BIT;
	if (num <= 0) return *this;
	else{
		if (num > size) num = size;
		QInt res;
		for (int i = size - 1; i >= num; i--)
			res.SetBitDataInt(i, (*this).GetBitDataInt(i - num));
		for (int i = num - 1; i >= 0; i--)
			res.SetBitDataInt(i, 0);
		return res;
	}
}

//dịch phải num bit
QInt QInt::operator >>(int num) {
	int size = MAX_LENGTH * NUM_BIT;
	if (num <= 0) return *this;
	else {
		if (num > size) num = size;
		bool FirstBit = (*this).GetBitDataInt(size - 1);
		QInt res;
		
		for (int i = size - num; i>=0 ;i--)
			res.SetBitDataInt(i, (*this).GetBitDataInt(i + num)); 
		for (int i = size - 1; i >= size - 1 - num; i--)
			res.SetBitDataInt(i, FirstBit & 1);

		return res;
	}
}

//Đổi dấu QInt
QInt QInt::operator-() {
	QInt res;
	//đổi dấu QInt
	for (int i = 0; i < MAX_LENGTH; i++)
		res.data[i] = ~(*this).data[i];

	//kiểm tra sự tràn số
	bool OverFlow = true;
	for(int i=MAX_LENGTH-1;i>=0;i--)
		if (OverFlow == true) {
			OverFlow = (res.data[i] == 0xffffffff);
			res.data[i]++;
		}
	return res;
}

//cộng 2 QInt
QInt QInt::operator + (QInt buff) {
	QInt res;
	bool OverFlow = false;
	for (int i = MAX_LENGTH - 1; i >= 0; i--){
		//nếu bị tràn số thì cộng thêm 1
		res.data[i] = (*this).data[i] + buff.data[i] + (OverFlow ? 1 : 0);
		//kiểm tra xem hiệu của số 0xfffffffff với (*this).data[i] có nhỏ hơn buff.data[i] hay không
		bool check1 = (0xffffffff - (*this).data[i]) < buff.data[i];
		//kiểm tra xem hiệu của số 0xfffffffff với (*this).data[i] có bằng buff.data[i] hay không
		bool check2 = (0xffffffff == buff.data[i] + (*this).data[i]);
		//check3 đúng khi check2 và OverFlow cùng đúng, tức là số trước đó bị tràn
		bool check3 = check2 && OverFlow;
		//bị tràn số khi hiệu của số 0xfffffffff với (*this).data[i] nhỏ hơn buff.data[i]
		//hoặc hiệu của số 0xfffffffff với (*this).data[i] bằng buff.data[i] và số trước đó bị tràn
		OverFlow = check1 || check3;
	}
	return res;
}

//trừ 2 QInt
QInt QInt::operator - (QInt buff) {
	//cộng với số đối của QInt buff
	return (*this) + (-buff);
}

//nhân 2 QInt
QInt operator * (QInt q, QInt m) {
	QInt a;
	int size=NUM_BIT*MAX_LENGTH;
	int Q_1 = 0;
	//QInt có độ lớn size bit nên vòng lặp while được thực hiện size lần
	while (size > 0) {
		int lastQ = q.GetBitDataInt(0);
		if (lastQ == 1 && Q_1 == 0) 
			a = a - m;
		else if (lastQ == 0 && Q_1 == 1) 
			a = a + m;

		Q_1 = lastQ;
		int lastA = a.GetBitDataInt(0);
		//dịch phải
		q = q >> 1;
		q.SetBitDataInt( 127, lastA);
		a = a >> 1;
		Q_1 = lastQ;
		size--;
	}
	return q;
}

//chia 2 QInt
//q: số bị chia
//m: số chia
QInt operator / (QInt q, QInt m) {
	QInt a;
	int size = NUM_BIT * MAX_LENGTH;

	//nếu khác dấu thì biến temp = 1
	bool temp = q.GetBitDataInt(127) ^ m.GetBitDataInt(127);
	bool sign = (temp == 1);

	//nếu q và m là số âm ta đưa nó về số không âm
	if (q.GetBitDataInt(127) == 1) q = -q;
	if (m.GetBitDataInt(127) == 1) m = -m;

	//QInt có độ lớn size bit nên vòng lặp while được thực hiện size lần
	while (size > 0) {
		int FirstBit = q.GetBitDataInt(127);
		a = a << 1;
		q = q << 1;
		a.SetBitDataInt(0, FirstBit);
		a = a - m;

		if (a.GetBitDataInt(127) == 1) {
			q.SetBitDataInt(0, 0);
			a = a + m;
		}
		else {
			q.SetBitDataInt(0, 1);
		}
		size--;
	}

	//nếu 2 số khác dấu nhau thì gán dấu trừ vào m
	if (sign) return -q;
	else return q;
}

//chuyển từ QInt sang hệ 2
string QInt::QIntToBin() {
	string res;
	int size = MAX_LENGTH * NUM_BIT;
	res.resize(size);
	for (int i = 0; i < size; i++)
		res[i] = (*this).GetBitDataInt(size - 1 - i) + '0';
	return res;
}

//chuyển từ QInt sang hệ 10
string QInt::QIntToDec() {
	string res;
	vector<bool> bin;
	for (int i = NUM_BIT * MAX_LENGTH - 1; i >= 0; i--)
		bin.push_back((*this).GetBitDataInt(i));
	res = BinToDecString(bin);
	return res;
}

//chuyển từ QInt sang hệ 16
string QInt::QIntToHex() {
	string temp = (*this).QIntToBin();
	return (BinToHexString(temp));
}


//chuyển từ QInt sang các hệ cơ số 2, 10, 16
string QInt::WriteQInt(string base) {
	string res;
	//chuyển từ QInt sang hệ 2
	if (base == "2") 
		res = (*this).QIntToBin();

	//chuyển từ QInt sang hệ 10
	if (base == "10") 
		res = (*this).QIntToDec();
	
	//chuyển từ QInt sang hệ 16
	if (base == "16") 
		res = (*this).QIntToHex();
	
	return res;
}

//xoay phải
QInt QInt::ror(int n)
{
	int t = 1;
	t <<= 31;
	QInt res = *this;
	for (int i = 0; i < n % 128; i++)
	{
		if (res.data[0] < 0 && res.data[3] % 2 == 0)
		{
			res = res >> 1;
			res.data[0] &= ~t;
		}
		else if (res.data[0] >= 0 && res.data[3] % 2 != 0)
		{
			res = res >> 1;
			res.data[0] |= t;
		}
		else
			res = res >> 1;
	}
	return res;
}

//xoay trái
QInt QInt::rol(int n)
{
	return this->ror(128 - n % 128);
}