#include <bits/stdc++.h>

using namespace std;

class Solution{

public:

	int maxProfit(vector<int>& prices){

		int buy = prices[0];
		int profit = 0;

		for(int i=0; i<prices.size(); i++){
			if(prices[i] < buy){
				buy = prices[i];
			} else if (prices[i] - buy > profit){
				profit = prices[i] - buy;
			}
		}

		return profit;
	}

};

int main(){

	Solution sol;

	vector<int> nums1 = {7,1,5,3,6,4};
	vector<int> nums2 = {7,6,4,3,1};

	int resul1 = sol.maxProfit(nums1);
	int resul2 = sol.maxProfit(nums2);

	cout << resul1 << endl;
	cout << resul2 << endl;


	return 0;
}