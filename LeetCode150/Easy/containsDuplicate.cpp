#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution{

    public:
        bool containsDuplicate(vector<int>& nums){

            unordered_set<int> vistos;

            for(int i=0; i<nums.size(); i++){

                if(vistos.find(nums[i]) != vistos.end()){
                    return true;
                } else{
                    vistos.insert(nums[i]);
                }
            }

            return false;
        }


};

int main(){

    Solution sol;

    vector<int> nums = {1,2,3,1};
    vector<int> nums2 = {1,2,3,4};
    vector<int> nums3 = {1,1,1,3,3,4,3,2,4,2};


    bool res = sol.containsDuplicate(nums);
    bool res2 = sol.containsDuplicate(nums2);
    bool res3 = sol.containsDuplicate(nums3);

    cout << res << endl;
    cout << res2 << endl;
    cout << res3 << endl;
    return 0;
}
