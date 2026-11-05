#include <iostream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution{
    public:

        int lengthOfLongestSubstring(string s){

            unordered_set<char> chars;

            int left = 0;
            int maxLen = 0;

            for(int right = 0; right < s.length(); right++){

                if(chars.count(s[right])){
                    chars.erase(s[left]);
                    left++;
                }

                chars.insert(s[right]);

                int currentLen = right - left + 1;

                if(currentLen > maxLen){
                    maxLen = currentLen;
                }
            }

            return maxLen;

        }
};

int main(){

    Solution s1;

    string s = "abcabcbbc";

    int sol1 = s1.lengthOfLongestSubstring(s);
    cout << sol1 << endl;


    return 0;
}
