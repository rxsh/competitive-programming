#include <bits/stdc++.h>

using namespace std;

class Solution{

public:

	int maxProfit(vector<int>& prices){

		int max = 0;
		int start = prices[0];

		for(int i=1; i<prices.size(); i++){
			if(start < prices[i]){
				max += prices[i] - start;
			}
			start = prices[i];
		}
		return max;
	}

};

int main(){

	Solution sol;

	vector<int> nums1 = {7,1,5,3,6,4};
	vector<int> nums2 = {1,2,3,4,5};
	vector<int> nums3 = {7,6,4,3,1};

	int resul1 = sol.maxProfit(nums1);
	int resul2 = sol.maxProfit(nums2);
	int resul3 = sol.maxProfit(nums3);

	cout << resul1 << endl;
	cout << resul2 << endl;
	cout << resul3 << endl;

	return 0;
}