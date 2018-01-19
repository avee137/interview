#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> hash; // number,index pair
	int max = *max_element(begin(nums),end(nums));
	hash.reserve(max);
        vector<int> v;
        int hi;
        for (auto x=0; x < nums.size(); x++){
            hi = target - nums[x];
            //cout << "hi: " << hi << " num: " << nums[x] << endl;
	    if(hi>0){
            	hash[hi] = 1;
	    }
        }
        for (auto y=0; y < nums.size(); y++){
            if ((hash[nums[y]] == 1) && (hash[target-nums[y]] == 1)){
                auto index1 = y;
                auto index2 = find(nums.begin(), nums.end(),(target-nums[y])) - nums.begin();
		if (index1 != index2){
            		//cout << "index1: " << index1 << " index2: " << index2 << endl;
                	v.push_back(index1);v.push_back(index2);
			break;
		}
		//cout << index1 << index2 << endl;
            }
            //cout << "hash , "<< nums[y] << endl;
        }
        return v;
    }
};


int main(){
	Solution s;
vector<int> v{230,863,916,585,981,404,316,785,88,12,70,435,384,778,887,755,740,337,86,92,325,422,815,650,920,125,277,336,221,847,168,23,677,61,400,136,874,363,394,199,863,997,794,587,124,321,212,957,764,173,314,422,927,783,930,282,306,506,44,926,691,568,68,730,933,737,531,180,414,751,28,546,60,371,493,370,527,387,43,541,13,457,328,227,652,365,430,803,59,858,538,427,583,368,375,173,809,896,370,789};
int t = 542;
	vector<int> r;
	r = s.twoSum(v,t);
	cout << "return" << endl;
	for (int i=0; i<r.size(); i++){
		cout << r[i] << ": "<< v[r[i]] << endl;
	}
	return 0;
}
