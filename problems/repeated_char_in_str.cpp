#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


string first_dup_char(string s){
	int i; string ret_str{};
	unordered_map<char, int> map_of_chars {};
	unordered_map<char,int>::iterator it;
	for(i=0; i<s.length(); i++){
		if(s[i] != ' '){
			it = map_of_chars.find(s[i]);
			if (it != map_of_chars.end()){
				it->second += 1;
				cout << "inserting : "<< s[i] << " :: count: "<<it->second << endl;
			} else {
				map_of_chars.insert(pair<char,int>(s[i], 1));
			}
		}
	}
	for (auto i: s){
		//cout << "searching: " << i << endl;
		auto it = map_of_chars.find(i);
		if (it != map_of_chars.end()){
			if(it->second > 1){
				ret_str = it->first;
				break;
			}
		}
	}
	
	return ret_str;
}


int main(){
	string s("asrthis s th as a repeated char");
	string c = first_dup_char(s);
	cout << "repeated char : " << c << endl ;
	return 0;
}
