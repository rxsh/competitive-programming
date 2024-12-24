#include <bits/stdc++.h>

using namespace std;

class Solution{

public:
	int hIndex(vector<int>& citations){
		int len = citations.size();
		sort(citations.begin(), citations.end());
		for(int i=0; i<len; i++){
			if(citations[i] >= (len - i)) return len - i;
		}

		return 0;
	}


};

int main(){

	Solution sol;

	vector<int> nums1 = {3,0,6,1,5};
	vector<int> nums2 = {1,3,1};

	int resul1 = sol.hIndex(nums1);
	int resul2 = sol.hIndex(nums2);
	cout << resul1 << endl;
	cout << resul2 << endl;


	return 0; 
}