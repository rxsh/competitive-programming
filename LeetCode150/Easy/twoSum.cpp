#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution{

    public:
        vector<int> twoSum(vector<int> sum, int target){

            unordered_map<int, int> vistos;

            for(int i=0; i<sum.size(); i++){

                int complemento = target - sum[i];

                if(vistos.find(complemento) != vistos.end()){
                    return {vistos[complemento], i};
                }
                else{
                    vistos[sum[i]] = i;
                }
            }


        }

};

int main(){

    Solution sol;

    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> res = sol.twoSum(nums, target);

    for(auto x : res){
        cout << x << " ";
    }
    cout << endl;


    vector<int> nums2 = {3,2,4};
    int target2 = 6;

    vector<int> res2 = sol.twoSum(nums2, target2);

    for(auto x : res2){
        cout << x << " ";
    }
    cout << endl;


    vector<int> nums3 = {3,3};
    int target3 = 6;

    vector<int> res3 = sol.twoSum(nums3, target3);

    for(auto x : res3){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
