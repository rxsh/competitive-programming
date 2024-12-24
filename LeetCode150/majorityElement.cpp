#include <bits/stdc++.h>

using namespace std;

class Solution{

public:

	int majorityElement(vector<int>& nums){

		sort(nums.begin(), nums.end());
		int n = nums.size();
		return nums[n/2];
	}

};

int main(){

	vector<int> nums1 = {3,2,3};
	vector<int> nums2 = {2,2,1,1,1,2,2};

	Solution sol;

	int resultado = sol.majorityElement(nums1);
	int resultado2 = sol.majorityElement(nums2);

	cout << "Elemento mayor: " << resultado << endl;
	cout << "Elemento mayor: " << resultado2;

	return 0;
}


/* other solution

sort(nums.begin(), nums.end());
int n = nums.size();
return nums[n/2];
*/