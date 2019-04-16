#include"StringHanding.h"

//Lấy ra số dư khi chia 1 số ở hệ 10 cho 2
int GetSurplus(string buff) {
	//lấy ra vị trí chữ số tận cùng
	int pos = buff.length() - 1;
	//chuyển kí tự sang số ta trừ đi 48
	//tương đương với kí tự '0'
	int res = buff[pos] - '0';
	//lấy ra số dư
	return res % 2;
}

//chuyển kí số từ hệ 16 sang hệ 2
string HexToBinChar(char c) {
	if (c == '0') return "0000";
	if (c == '1') return "0001";
	if (c == '2') return "0010";
	if (c == '3') return "0011";
	if (c == '4') return "0100";
	if (c == '5') return "0101";
	if (c == '6') return "0110";
	if (c == '7') return "0111";
	if (c == '8') return "1000";
	if (c == '9') return "1001";
	if (c == 'A') return "1010";
	if (c == 'B') return "1011";
	if (c == 'C') return "1100";
	if (c == 'D') return "1101";
	if (c == 'E') return "1110";
	if (c == 'F') return "1111";
	return "";
}

//chuyển kí số từ hệ 2 sang hệ 16
char BinToHexChar(string num) {
	if (num == "0000") return '0';
	if (num == "0001") return '1';
	if (num == "0010") return '2';
	if (num == "0011") return '3';
	if (num == "0100") return '4';
	if (num == "0101") return '5';
	if (num == "0110") return '6';
	if (num == "0111") return '7';
	if (num == "1000") return '8';
	if (num == "1001") return '9';
	if (num == "1010") return 'A';
	if (num == "1011") return 'B';
	if (num == "1100") return 'C';
	if (num == "1101") return 'D';
	if (num == "1110") return 'E';
	if (num == "1111") return 'F'; 
	return '\0';
}

//chuyển chuỗi ở hệ 16 sang hệ 2
string HexToBinString(string buff) {
	string res = "";
	for (int i = 0; i < buff.size(); i++)
		res += HexToBinChar(buff[i]);
	if (res.size() < 128)
	{
		int sub = 128 - res.size();
		string result;
		for (int i = 0; i < sub; i++)
			result += '0';
		result += res;
		return result;
	}
	else return res;
}

//chuyển chuỗi ở hệ 2 sang hệ 16
string BinToHexString(string buff) {
	string res = "";
	string tmp = "";
	string temp = buff;
	int sz = buff.size();

	//nếu độ dài chuỗi buff không là bội của 4 thì ta thêm số 0 vào đầu chuỗi cho thỏa điều kiện
	if (sz % 4 != 0) {
		int NumZero = 4 * (sz / 4 + 1) - sz;
		for (int i = 0; i < NumZero; i++)
			tmp += '0';
	}
	tmp += temp;

	//cứ mỗi 4 bit kế tiếp nhau ta đổi nó qua hệ 16
	for (int i = 0; i < tmp.size(); i += 4) {
		string check = tmp.substr(i, 4);
		char check1 = BinToHexChar(check);
		res += check1;
	}

	//xóa các chữ số 0 thừa
	int pos = -1;
	for (int i = 0; i < res.size() - 1; i++)
	{
		if (res[i] == '0' && res[i + 1] != '0') {
			pos = i;
			break;
		}
	}

	bool check = false;//biến check kiểm tra xem khoảng giữa 0 và vị trí pos có kí tự nào khác 0 hay không
	for (int i = 0; i < pos; i++)
		if (res[i] != '0')
			check = true;

	if (check == false) {
		while (pos >= 0) {
			res.erase(0, 1);
			pos--;
		}
	}

	int num = 0;
	for (int i = 0; i < res.size(); i++)
		if (res[i] == '0')
			num++;
	if (num == res.size())
		res = "0";
	return res;
}

// chuyển ký tự sang số
int stringToNum(char c)     
{
	return c - '0';
}

//chuyển số sang ký tự
char numToString(int n)     
{
	return (char)(n + 48);
}

//làm 2 chuỗi có chiều dài bằng nhau
void chuanHoa(string &a, string &b) 
{
	int l1 = a.length(), l2 = b.length();
	if (l1 >= l2)
	{
		b.insert(0, l1 - l2, '0');    //chèn vào đầu của b các kí tự '0'
	}
	else
	{
		a.insert(0, l2 - l1, '0');    //chèn vào đầu của b các kí tự '0'
	}
}

//tính tổng 2 số bằng chuỗi
string sum(string a, string b)  
{
	string s = "";
	chuanHoa(a, b);      // chuẩn hóa chuỗi 
	int l = a.length();

	int temp = 0;
	for (int i = l - 1; i >= 0; i--)   //duyệt và cộng
	{
		temp = stringToNum(a[i]) + stringToNum(b[i]) + temp;    //tính tổng từng đôi một
		s.insert(0, 1, numToString(temp % 10));         //gán phần đơn vị vào
		temp = temp / 10;     //lấy lại phần hàng chục
	}
	if (temp>0)  // nếu hàng chục > 0 thì thêm vào kết quả
	{
		s.insert(0, 1, numToString(temp));
	}
	return s;
}

//nhân 1 số nhỏ với số lớn
string nhanNho(char a, string b)
{
	string s = "";
	int temp = 0; //đây là biến nhớ
	for (int i = b.length() - 1; i >= 0; i--){
		temp = stringToNum(a) * stringToNum(b[i]) + temp; //nhân số nhỏ a với từng số của b
		s.insert(0, 1, numToString(temp % 10)); //chèn phần dư của temp vào
		temp = temp / 10;
	}

	if (temp>0)	
		s.insert(0, 1, numToString(temp)); //nếu còn nhớ thì chèn vào đầu chuỗi
	
	return s;
}

// nhân 2 số lớn
string nhan(string a, string b)    
{
	string s = "";
	int l = a.length();
	string s1;
	for (int i = l - 1; i >= 0; i--){
		s1 = nhanNho(a[i], b);   // nhân từng chữ số của a với số b
		s1.insert(s1.length(), l - i - 1, '0');
		s = sum(s, s1);  // cộng dồn lại
	}
	return s;
}

//tính lũy thừa
string luythua(string a, int n){
	string res = "1";
	//if (n == 1)
	//return a;
	for (int i = 0; i < n; i++)
		res = nhan(res, a); //nhân n lần số a
	return res;
}

//chia số ở hệ 10
string DecDevide(string buff) {
	if (buff == "1")
		return "0";
	string a = "";
	int nho = 0, nguyen; //khởi tạo biến nhớ = 0
	char temp;
	for (int i = 0; i < buff.size(); i++){
		int index = buff[i] - 48; //chuyến kí tự thứ i thành số
		nguyen = (nho * 10 + index) / 2; //phần nguyên chia được
		if (index % 2 != 0)
			nho = index % 2;
		else
			nho = index % 2;
		temp = numToString(nguyen); //đổi số nguyên vừa chia được về ký tự
		a.push_back(temp); //đưa phần nguyên vừa chia được vào chuỗi
		while (a[0] == '0') // xóa số 0 thừa ở đầu
			a.pop_back();
	}
	return a;
}

//cộng 1 để thành số bù 2
vector<bool> CongBit1(vector<bool> res)
{
	int nho = 1;
	int i = res.size() - 1;
	//vòng lặp dừng khi biến nhớ = 0
	while (nho != 0) {
		if (res[i] == 0)
		{
			res[i] = 1;
			nho = 0;
		}
		else
		{
			res[i] = 0;
		}
		i--;
	}
	return res;
}

//trừ để về số bù 1
vector<bool> TruBit1(vector<bool> res)
{
	int nho = 1;
	int i = res.size() - 1;
	//vòng lặp dừng khi biến nhớ = 0
	while (nho != 0) {
		if (res[i] == 1)
		{
			res[i] = 0;
			nho = 0;
		}
		else
		{
			res[i] = 1;
		}
		i--;
	}
	return res;
}

//đổi sang số bù 2
vector<bool> SoBu2(vector<bool> res) 
{
	for (int i = 0; i < res.size(); i++){
		if (res[i] == 1) //đổi sang số bù một bằng phép toán NOT
			res[i] = 0;
		else
			res[i] = 1;
	}
	res = CongBit1(res); //cộng thêm bit 1 để trở thành số bù 2
	return res;
}

//chuyển số bù 2 sang số lượng dấu
vector<bool> SoBu2SangSoLuongDau(vector<bool> res)
{
	res = TruBit1(res); //trừ bit 1 để về số bù 1
	//thực hiện phép toán NOT để về dãy bit dương
	for (int i = 0; i < res.size(); i++) 
	{
		if (res[i] == 0)
			res[i] = 1;
		else
			res[i] = 0;
	}
	return res;
}

//chuyển từ hệ 10 sang hệ 2
vector<bool> DecToBinString(string buff) {
	vector<bool> res;
	string temp = buff;
	res.resize(128);
	for (int i = 0; i < res.size(); i++) //khởi tạo dãy toàn bit 0
		res[i] = 0;
	int j = res.size();
	//kiểm tra số âm
	if (buff[0] == '-') {
		temp = buff.substr(1, buff.length()); //loại bỏ dấu '-' ở đầu chuỗi xong thao tác như số dương
		while (temp != "0"){
			bool x = bool(GetSurplus(temp)); //lấy số dư sau mỗi lần chia 2
			res[--j] = x; //chèn vào vector 
			temp = DecDevide(temp); //chia 2 con số
		}
		res = SoBu2(res); // đổi về số bù 2
	}
	else{
		while (temp != "0"){
			bool x = bool(GetSurplus(temp)); //lấy số dư sao mỗi lần chia 2
			res[--j] = x; //chèn vào vector 
			temp = DecDevide(temp); //chia 2 con số
		}
	}
	return res;
}

//chuyển từ hệ 2 sang hệ 10
string BinToDecString(vector<bool> x)
{

	string res = ""; //khởi tạo chuỗi kết quả
	int j = 0;
	// nếu bắt đầu là 0 thì là số dương còn 1 là số âm
	if (x[0] == 0) {
		for (int i = x.size() - 1; i >= 0; i--)
		{
			if (x[i] == 1)
				res = sum(res, luythua("2", j)); // nếu x[i] = 1 thì lấy chuỗi res + 2^j
			j++;
		}
	}
	else{
		x = SoBu2SangSoLuongDau(x); //đổi từ số bù 2 về số lượng dấu xong thao tác như số dương
		for (int i = x.size() - 1; i >= 0; i--){
			if (x[i] == 1)
				res = sum(res, luythua("2", j)); // nếu x[i] = 1 thì lấy chuỗi res + 2^j
			j++;
		}
		res.insert(res.begin(), '-'); //thêm dấu trừ vào đầu chuỗi
	}

	if (res.length() == 0)
		res = "0";
	return res;
}