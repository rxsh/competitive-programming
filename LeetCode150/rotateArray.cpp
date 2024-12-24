#include <bits/stdc++.h>

using namespace std;

class Solution{

public:
	void rotate(vector<int>& nums, int k){

		int n = nums.size();
		k = k % n;

		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin()+ k);
		reverse(nums.begin() + k, nums.end());

	}
};

int main(){

	vector<int> nums1 = {1,2,3,4,5,6,7};
	int k1 = 3;
	vector<int> nums2 = {-1, -100, 3, 99};
	int k2 = 2;

	Solution sol;
	sol.rotate(nums1,k1);
	sol.rotate(nums2,k2);

	for(int i=0; i<nums1.size(); i++){
		cout << nums1[i] << " ";
	}

	cout << endl;

	for(int j=0; j<nums2.size(); j++){
		cout << nums2[j] << " ";
	}

	return 0;
}