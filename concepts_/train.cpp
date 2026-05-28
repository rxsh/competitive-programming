#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int contString(int L, int S){

    vector<vector<int>> dp(L+1, vector<int>(S+1,0));
    dp[0][0] = 1;


    for(int i=1; i<=26;i++){
        for(int j=L; j>=1; j--){
            for(int sum=S; sum>=i; sum--){
                dp[j][sum] += dp[j-1][sum-i];
            }

        }
    } 

    return dp[L][S];
}

int main(){


    int L, S, cases=1,res;
    while(cin >> L >> S && !(L==0 && S==0)){
        res = contString(L,S);
        cout << "Case " << cases++ << ": " << res << endl;
    }



    return 0;
}

