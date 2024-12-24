#include <bits/stdc++.h>

using namespace std;

class Solution{

public:
	bool canJump(vector<int>& nums){

		int targetNumIndex = nums.size() - 1;
		for(int i = nums.size() - 2; i >= 0; i--){
			if(targetNumIndex <= i + nums[i]){
				targetNumIndex = i;
			}
		}

		return targetNumIndex == 0;
	}
};

int main(){

	Solution sol;

	vector<int> nums1 = {2,3,1,1,4};
	vector<int> nums2 = {3,2,1,0,4};

	bool resul = sol.canJump(nums1);
	bool resul2 = sol.canJump(nums2);

	cout << resul << endl;
	cout << resul2 << endl;

	return 0;
}