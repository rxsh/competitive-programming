#include <iostream>
#include <vector>

using namespace std;

int flipSol(vector<int>& arr) {
    int vueltas = 0;

    for (int i = 0; i < arr.size() - 1; i++) { 
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                vueltas++;
            }
        }
    }
    return vueltas;
}

int main()
{
    int N;
    while (cin >> N) {
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int answer = flipSol(arr);
        cout << "Minimum exchange operations : " << answer << endl;
    }
    return 0;
}