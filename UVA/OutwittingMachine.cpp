#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int testCases, caseNum = 0;
    cin >> testCases;

    while (testCases--) {
        int n = 5; // Number of elements we need to find
        int m = n * (n - 1) / 2; // Number of pairwise sums
        vector<int> sums(m);

        // Read the pairwise sums
        for (int i = 0; i < m; i++) {
            cin >> sums[i];
        }
        sort(sums.begin(), sums.end());

        cout << "Case " << ++caseNum << ":";

        multiset<int> initialSet(sums.begin() + 2, sums.end()); // Skip first two elements
        bool solutionFound = false;

        // Try to determine A[0], A[1], and A[2] based on pairs
        for (int i = 2; i < m; i++) {
            int possibleSum = (sums[0] + sums[1] + sums[i]);

            if (possibleSum % 2 != 0) continue;

            vector<int> result(n);
            result[0] = possibleSum / 2 - sums[i];
            result[1] = possibleSum / 2 - sums[1];
            result[2] = possibleSum / 2 - sums[0];

            multiset<int> remainingSums = initialSet;
            remainingSums.erase(remainingSums.find(sums[i]));

            bool validSolution = true;

            // Calculate remaining A[j] values and validate the pairs
            for (int j = 3; j < n; j++) {
                int minElement = *remainingSums.begin();
                result[j] = minElement - result[0];
                remainingSums.erase(remainingSums.begin());

                // Validate current result[j] with all previous values
                for (int k = 1; k < j; k++) {
                    int expectedSum = result[j] + result[k];
                    auto it = remainingSums.find(expectedSum);
                    if (it == remainingSums.end()) {
                        validSolution = false;
                        break;
                    }
                    remainingSums.erase(it);
                }
                if (!validSolution) break;
            }

            // If a valid solution is found, print it and break
            if (validSolution) {
                solutionFound = true;
                for (int num : result) {
                    cout << " " << num;
                }
                cout << endl;
                break;
            }
        }

        if (!solutionFound) {
            cout << " Impossible" << endl;
        }
    }

    return 0;
}
