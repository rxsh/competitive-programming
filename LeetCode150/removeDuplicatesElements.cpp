#include <bits/stdc++.h>

using namespace std;

class Solution{

public:

	int removeDuplicates(vector<int>& nums){

		int index=1;
		for(int i=1; i<nums.size(); i++){
			if(nums[i] != nums[i-1]){
				nums[index] = nums[i];
				index++;
			}
		}
		return index++;

	}
};

int main(){

	vector<int> nums1 = {1,1,2};
	vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};

	Solution sol;
	int newSize = sol.removeDuplicates(nums1);
	int newSize2 = sol.removeDuplicates(nums2);

	for(int i=0; i<newSize; i++){
		cout << nums1[i] << " ";
	}

	cout << endl;


	for(int i=0; i<newSize2; i++){
		cout << nums2[i] << " ";
	}

	cout << endl;

	return 0;
}