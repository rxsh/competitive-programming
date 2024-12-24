#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int max_Coins(vector<int>& coins, int cont=1){

    int initValue = coins[0];
    for(int i=1; i<coins.size(); i++){
        if(initValue <= coins[i]){
            initValue += coins[i];
            cont++;
        }
    }

    return cont++;
}

int main(){

    int T; cin >> T;
    int numberOfCoins;
    while(T--){

        cin >> numberOfCoins;

        vector<int> coins(numberOfCoins);

        int cont=1;
        for(int i=0; i<numberOfCoins;i++){
            cin >> coins[i];
        }

        cout << max_Coins(coins,cont) << endl;
    }

    return 0;
}