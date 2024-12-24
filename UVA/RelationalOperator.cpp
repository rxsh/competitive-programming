#include <bits/stdc++.h>

using namespace std;

int main(){

	int T; 
	cin >> T;
	long long a, b;


	for(int i=1; i<=T;i++){
		cin >> a; 
		cin >> b;
		if(a < b){
			cout << "<" << endl;
		}
		if(a > b){
			cout << ">" << endl;
		}
		if (a == b){
			cout << "=" << endl;
		}
	}

	return 0;
}

