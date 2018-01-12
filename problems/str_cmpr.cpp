#include <iostream>
#include <cctype>

using namespace std;


int main(){
	char str1[] = "HelloWorld";
	char str2[] = "helloworld";
	int l1 = sizeof(str1)/sizeof(str1[0]);
	int l2 = sizeof(str2)/sizeof(str2[0]);

	int i;
	for (i=0 ; i<l1; i++){
		str1[i] = tolower(str1[i]);
	}
	cout << str1 << endl;
	return 0;
}
