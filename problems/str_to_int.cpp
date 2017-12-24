#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int str_to_int (string s_int){
	int l = s_int.length();
	char asci_zero = '0';
	bool neg = false;
	int res = 0;
	int place_val = 0;
	auto x = 0;	
	if (s_int[0] == '-'){
		neg = true;
		x =1;
	}

	while(x < l){
		place_val = l-1-x;
		res += (s_int[x]-asci_zero)*pow (10, place_val); 
		x++;
	}
	if (neg){
		return -res;
	}else {
		return res;
	}
}

string int_to_str(int i){
	string s_int="";
	int rem, digit, i_int;
	char c_digit;
	if (i <0)
		i_int = -i;
	else
		i_int = i;
	while (i_int){
		digit = i_int % 10;

		//cout << digit << endl;
		//cout << c_digit << endl;
		c_digit = '0'+digit;

		s_int += c_digit;
		i_int = i_int / 10;
	}
	std::reverse(s_int.begin(), s_int.end());
	if (i< 0){
		return "-"+ s_int ;
	}else {
		return s_int;
	}
}

int main(){
	string num = "123456";
	int n = str_to_int(num);
	cout << n << endl;
	
	string num1 = "-123456";
	int n1 = str_to_int (num1);
	cout << n1 << endl;
	string s = int_to_str(n);
	cout <<	s << endl ;
	cout << int_to_str(n1) << endl ;
	return 0;
}
