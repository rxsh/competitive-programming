#include <bits/stdc++.h>

using namespace std;

int main(){

	for(int i=0; i<n; i++){
		if(array[i] == x){
			// x found at index i
		}

	}

	// method 1
	int a = 0, b = n-1;
	while (a <= b){
		int k = (a+b)/2;
		if(array[k] == x){
			// x found at index k
		}
		if(array[k] > x) b = k-1;
		else a = k+1;
	}

	// method 2
	int k = 0;
	for(int b=n/2; b>=1; b/=2){
		while(k+b < n && array[k+b] <= x) k += b;
	}	
	if(array[k] == x){
		// x found at index k
	}

	return 0;
}