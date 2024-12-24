#include <bits/stdc++.h>

using namespace std;

class Solution{

public:

	int jump(vector<int>& nums){

		for(int i=1; i < nums.size(); i++){
			nums[i] = max(nums[i] + i, nums[i-1]);
		}

		int ind = 0;
		int ans = 0;

		while(ind < nums.size() - 1){
			ans++;
			ind = nums[ind];
		}

		return ans;
	}


};

int main(){

	Solution sol;

	vector<int> nums1 = {2,3,1,1,4};
	vector<int> nums2 = {2,3,0,1,4};

	int resul1 = sol.jump(nums1);
	int resul2 = sol.jump(nums2);

	cout << resul1 << endl;
	cout << resul2 << endl;



	return 0;
}