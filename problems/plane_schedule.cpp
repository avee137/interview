#include <iostream>
#include <algorithm>


using namespace std;


int main(){
	int arrival[3] = {570, 675, 990};
	int dep[3] = {705, 690, 1005};
	int i=1, j=0;
	int maxp = 1, count=1;
	sort (arrival, arrival+3);
	sort (dep, dep+3);
	while (i < 3 && j < 3) {
		if (arrival[i] < dep[j]){
			count++;
			i++;
			if (count > maxp){
				maxp = count;
			}
		}else {
			count--;
			j++;
		}
	}
	cout << "maxp: " << maxp << endl;
	return 0;
}
