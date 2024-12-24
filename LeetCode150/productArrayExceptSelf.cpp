#include <bits/stdc++.h>

using namespace std;

class Solution{

public:
	vector<int> productExceptSelf(vector<int>& nums){
		vector<int> output;
		for(int i=0; i<nums.size();i++){
			int product = 1;
			for(int j=0; j<nums.size();j++){
				if(i == j) continue;
				product *= nums[j];
			}
			output.push_back(product);
		}
		return output;
	}
};

int main(){

	Solution sol;

	vector<int> nums1 = {1,2,3,4};
	vector<int> nums2 = {-1,1,0,-3,3};


	vector<int> result = sol.productExceptSelf(nums1);
	vector<int> result2 = sol.productExceptSelf(nums2);

	for(int num : result){
		cout << num << " ";
	}

	cout << endl;

	for(int num : result2){
		cout << num << " ";
	}
	
	return 0;

	return 0;
}