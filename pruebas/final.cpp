#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> rf(vector<int> raro, int tam){

    for(int i=0; i<tam; i++){
        cin >> raro[i];
    }

    for(auto k : raro){
        cout << k << endl;
    }

    return raro;

}

int main(){

    vector<int> ref;
    int tam = 10;
    rf(ref, tam);


    return 0;
}