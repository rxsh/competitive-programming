#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){

    string line;
    while(getline(cin, line)){

        vector<int> nums;
        int num;

        stringstream ss(line);

        while(ss >> num){
            nums.push_back(num);
        }

        stack<pair<int,int>> st;
        bool isValid = true;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0){
                st.push(make_pair(-nums[i], 0));
            } else{
                if(st.empty() || st.top().first != nums[i]){
                    isValid = false;
                    break;
                }

                if(st.top().second >= nums[i]){
                    isValid = false;
                    break;
                }

                int toySize = st.top().first;
                int nestedSum = st.top().second;
                st.pop();

                if(!st.empty()){
                    st.top().second += toySize;
                }
            }
        }

        if(!st.empty()){
            isValid = false;
        }

        if(isValid){
            cout << ":-) Matrioshka!" << endl;
        } else{
            cout << ":-( Try again." << endl;
        }
    }

    return 0;
}