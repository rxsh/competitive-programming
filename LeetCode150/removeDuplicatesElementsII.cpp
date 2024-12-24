#include <bits/stdc++.h>

using namespace std;

class Solution{

public:

	int removeDuplicates(vector<int>& nums){

		int j=1;
		for(int i=1; i<nums.size(); i++){
			if(j == 1 || nums[i] != nums[j-2]){
				nums[j++] = nums[i];
			}
		}
		return j;
	}
};

int main(){

	vector<int> nums1 = {1,1,1,2,2,3};
	vector<int> nums2 = {0,0,1,1,1,1,2,3,3};

	Solution sol;
	int newSize = sol.removeDuplicates(nums1);
	int newSize2 = sol.removeDuplicates(nums2);

	for(int i=0; i < newSize; i++){
		cout << nums1[i] << " ";
	}
	cout << endl;

	for(int j=0; j < newSize2; j++){
		cout << nums2[j] << " ";
	}

	return 0;
}