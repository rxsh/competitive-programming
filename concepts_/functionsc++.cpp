#include <bits/stdc++.h>

using namespace std;

/* 
	lower_bounds returns a pointer to the first array element whose value is at least x.
	upper_bound returns a pointer to the first array element whose value is larger than x.
	equal_range returns both above pointers
*/

int main(){

	auto k = lower_bound(array,array+n,x)-array;
	if(k < n && array[k] == x){
		// x found at index k
	}

	auto a = lower_bound(array, array+n, x);
	auto b = upper_bound(array, array+n, x);

	cout << b - a << "\n";

	auto r = equal_range(array,array+n,x);
	cout << r.second-r.first << "\n";


	// Finding the smallest solution 

	int x = -1;
	for(int b = z; b >= 1; b /= 2){
		while (!ok(x+b)) x+=b;
	}
	int k = x+1;

	return 0;
}