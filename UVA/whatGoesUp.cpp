#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para encontrar la subsecuencia estrictamente creciente más larga
void findLongestIncreasingSubsequence(const vector<int>& sequence, vector<int>& lis) {
    int n = sequence.size();
    if (n == 0) return;

    vector<int> dp(n, -1);
    vector<int> lisIndices;
    vector<int> position(n, -1);

    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(lisIndices.begin(), lisIndices.end(), i, [&](int idx1, int idx2){
            return sequence[idx1] < sequence[i];
        });

        int lisLength = it - lisIndices.begin();

        if (it == lisIndices.end()) {
            lisIndices.push_back(i);
        } else {
            *it = i;
        }

        if (lisLength > 0) {
            position[i] = lisIndices[lisLength - 1];
        }

        dp[i] = lisLength;
    }

    int lastIndex = lisIndices.back();
    while (lastIndex != -1) {
        lis.push_back(sequence[lastIndex]);
        lastIndex = position[lastIndex];
    }

    reverse(lis.begin(), lis.end()); 
}

int main() {
    vector<int> sequence;
    int num;

    while (cin >> num) {
        sequence.push_back(num);
    }

    vector<int> lis;
    findLongestIncreasingSubsequence(sequence, lis);

    cout << lis.size() << endl;
    cout << "-" << endl;

    for (int x : lis) {
        cout << x << endl;
    }

    return 0;
}
