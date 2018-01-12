#include <iostream>
#include <string>
#include <set>

using namespace std;

set<char> setOfChars;

char first_dup_char(string s){
	int i;
	set<char>::iterator it;
	for(i=0; i<s.length(); i++){
		it = setOfChars.find(s[i]);
		if (it != setOfChars.end()){
			return s[i];
		} else {
			setOfChars.insert(s[i]);
		}
	}
	return '\0';
}


int main(){
	string s("this th as a repeated char");
	char c = first_dup_char(s);
	cout << "repeated char : " << c << endl ;
	return 0;
}
