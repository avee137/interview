// you can use includes, for example:
// #include <algorithm>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int i, j;
    sort(A.begin(),A.end());
    for (auto x=A.begin(); x!=A.end(); x++){
        cout << *x << "\t";
    }
    cout << endl;
    auto len = A.size();
    for (i=0,j=i+1;i<len-1 ;i++, j++){
        if ((A[j]-A[i]) > 1){
            if (A[i] > 0){
                return A[i]+1;
            }else{
                return 1;
            }
        }
    }
    auto max = A[len-1];
    return max+1;
}

int main(){
	vector <int> v {1, 3, 6, 4, 1, 2};
	int ret = solution(v);
	cout << "result: " << ret << endl;
	return 0;
}
