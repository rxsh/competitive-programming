#include<bits/stdc++.h>

using namespace std;

int main(){

	set<int>::iterator it = s.begin();
	auto it = s.begin(); // shorter way

	// The element which an iterator points can be accessed using the * symbol.
	auto it = s.begin();
	cout << *it << "\n";

	/*
	Iterators can be moved using the operators ++ (forward) and --(backward), meaning that the iterator moves to the next
	or previous element in the set.
	*/
	for(auto it = s.begin(); it != s.end(); it++){
		cout << *it << "\n";
	}

	// this code prints the largest element in the set:
	auto it = s.end(); it--;
	cout << *it << endl;

	// the function find(x) returns an iterator that points to an element whose value is x.
	auto it = s.find(x);
	if (it == s.end()){
		// x is not found
	}

	/*
	The function lower_bound(x) returns an iterator to the smallest element in the set whose value is at least x, and the function upper_bound(x)
	returns an iterator to the smallest element in the set whose value is larger than x.
	*/

	// this code finds the element nearest to x:
	auto pit = r.lower_bound(k);
	if (pit == r.begin()){
		cout << *pit << "\n";
	} else if(pit == r.end()) {
		pit--;
		cout << *pit << "\n";
	} else {
		int m = *pit; pit--;
		int n = *pit;
		if (k-n < m-k) cout << n << "\n";
		else cout << m << "\n";
	}


	return 0;
}