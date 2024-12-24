#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int C; // Número de casos
    cin >> C;
    
    for (int t = 1; t <= C; ++t) {
        int N, H, Ta, Td;
        cin >> N >> H >> Ta >> Td;
        
        vector<int> heights(N);
        for (int i = 0; i < N; ++i) {
            cin >> heights[i];
        }
        
        sort(heights.begin(), heights.end());
        
        int left = 0, right = N - 1;
        int totalTime = 0;
        
        while (left <= right) {
            if (left == right) {
                totalTime += Ta;
                break;
            }
            
            if (heights[left] + heights[right] < H) {
                totalTime += Td;  // Van juntos
                left++;
                right--;
            } else {
                totalTime += Ta;
                right--;
            }
        }
        
        cout << "Case " << t << ": " << totalTime << endl;
    }
    
    return 0;
}
