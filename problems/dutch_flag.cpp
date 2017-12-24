#include <iostream>
#include <vector>
using namespace std;



int main() {
	cout << "dutch national flag" << endl;

	vector<int> v = {1,2,32,11,7,49,17,3,8,9};
	
	cout << "before partition:" << endl;
	for (auto x=0; x < v.size(); x++){
		cout << v[x] << "\t";
	} 
	cout << endl;
	int p = 7;
	int i, j;
	int pivot = v[p];

	((cout << "pivot index: " << p << "\t")<< "val: " << v[p] )<< endl;
	
	//first pass all smaller elaments to the beginning of the array
	auto smaller_index = 0;
	for(i=0; i<v.size(); i++){
		if (v[i] < pivot){
			swap (v[i], v[smaller_index]);
			smaller_index++;
		}
	}

	auto larger_index = v.size()-1;
	for (i=v.size()-1; i>=0 && v[i] >= pivot ; i--){
		if (v[i]>pivot){
			swap (v[i], v[larger_index]);
			larger_index--;
		}
	}

	cout << "after partition:" << endl;
	for (auto x=0; x < v.size(); x++){
		cout << v[x] << "\t";
	} 
	cout << endl;
	return 0;
}
