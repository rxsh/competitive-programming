#include <iostream>
#include <vector>
using namespace std;

int countStrings(int L, int S) {
    vector<vector<int>> dp(L + 1, vector<int>(S + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i < 27; i++) { 
        for (int length = L; length >= 1; length--) { 
            for (int sum = S; sum >= i; sum--) { 
                dp[length][sum] += dp[length-1][sum-i];
            }
        }
    }

    return dp[L][S];
}

int main() {
    int L, S, cases = 1, res;
    
    while (cin >> L >> S && !L == 0 && !S == 0) {
        res = countStrings(L, S);
        cout << "Case " << cases++ << ": " << res << endl;
    }
    
    return 0;
}