#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip> // input output manipulation !!

using namespace std;

//to compile : g++ name.cpp -o name.o -std=c++11
int main() {
	unordered_map <int,int> umap {{1,1},{2,1},{3,0},{4,1},{5,0},{6,1},{7,1}};
	//map <int,int> umap {{1,1},{2,1},{3,0},{4,1},{5,0},{6,1},{7,1}};
	//vector<int> v ={-1, 0, 1, 2, -1, -4};
	vector<int> v ={-2,0,1,1,2};
	int sum = 0;
	sort(v.begin(),v.end());
	/*
	unordered_map <int, int> mymap;
	unordered_map <int, int>::const_iterator mymap_it;
	// method 1:
	// store the third element in a map
	for (auto i=0; i < v.size(); i++){
		mymap.insert(make_pair(v[i],i));
	}
	// add first two and lookup if third in map
	for (auto i=0; i<v.size()-1; i++){
		for (auto j=i+1; j<v.size();j++){
			sum = v[i]+v[j];
			mymap_it = mymap.find(0-sum);
			if(mymap_it != mymap.end()){
				//cout <<"set: " <<v[i]<<v[j]<<mymap_it->first<< endl;
			}
		}
	}
	*/
	//method 2
	// sort
	// iterate over array and keep looking for elements in sub array both way
	sum = 0;
	cout << "method 2: sum needed: " << sum <<  endl;
	//set<vector<int>> myset;
	vector<vector<int>> myset;
	for(auto i=0; i< v.size()-2; i++){
		auto j = i+1;
		auto k = v.size()-1;
		auto rem = sum - v[i];
		cout << v[i]<< v[j]<<v[k]<<" rem: "<< rem<< endl;
		while(j<k){
			if(v[j]+v[k] > rem ){
				k--;
			}else if(v[j]+v[k] < rem){
				j++;
			}else{
				//cout<< "set: " << i << j << k << endl;
				vector<int> v1{0,0,0};
				v1[0]=v[i]; v1[1]=v[j]; v1[2]=v[k];
				myset.emplace_back(v1);
				k--;j++;
			}
		}
	}	
	for(auto x: myset){
		cout << x[0] << x[1] << x[2] << endl;
	}
	return 0;
}

