#include <vector>
#include <iostream>

using namespace std;

int main(){
	vector<int> v {1,2,4,5};
	for (auto x=0; x<v.size(); x++){
		cout << v[x] << endl;
	}
	return 0;
}
