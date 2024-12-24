#include <bits/stdc++.h>

using namespace std;

int main(){

    int T;
    int numbers;
    int next;
    int maximo;

    cin >> T;
    for(int i=0; i<T; i++){
        cin >> numbers;
        maximo = -1;
        
        while(numbers--){
            cin >> next;
            maximo = max(maximo, next);
        }
        cout << "Case " << i+1 << ": " << maximo << endl;
    }

    return 0;
}