#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){

    int T; cin >> T;
    int numberElephants, maxWeigth;
    while(T--){
        cin >> numberElephants >> maxWeigth;
        
        int cantElephants=0;
        int weightActual=0;

        int weigthElephant;
        vector<int> elephants;

        for(int i=0; i<numberElephants; i++){
            cin >> weigthElephant;
            elephants.push_back(weigthElephant);
        }

        sort(elephants.begin(), elephants.end());

        for(int i=0; i<numberElephants;i++){
            if(weightActual + elephants[i] <= maxWeigth){
                weightActual += elephants[i];
                cantElephants++;
            }
        }

        cout << cantElephants << endl;

    }

    return 0;
}