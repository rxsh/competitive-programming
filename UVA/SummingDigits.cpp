#include <bits/stdc++.h>

using namespace std;

int main(){

    string T;

    while(cin >> T && T != "0"){
        long long answer;
        while(T.length() != 1){
            answer = 0;
            for(int i=0; i < T.length(); i++){
                answer += T[i] - '0';
            }
            T = to_string(answer);
        }    
        cout << T << endl;
    }

    return 0;
}