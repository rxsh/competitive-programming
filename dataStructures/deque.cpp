#include <bits/stdc++.h>

using namespace std;

int main(){

	// A deque is a dynamic array whose size can be efficiently changed at both ends of the array

	deque<int> d;
	d.push_back(5); // [5]
	d.push_back(2); // [5,2]
	d.push_front(3); // [3,5,2]

	cout << "Before to delete: " << endl;
	for(auto it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}

	d.pop_back(); // [3,5]
	d.pop_front(); // [5]

	cout << "\n" << "After to delete: " << endl;
	for(auto it = d.begin(); it != d.end(); it++){
		cout << *it << " ";
	}


	return 0;
}