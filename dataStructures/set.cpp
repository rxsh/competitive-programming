#include<bits/stdc++.h>

using namespace std;

int main(){

	/* Set Structures -> is a data structure that maintains a collection of elements.
	   The C++ standard library contains two set implementations:
	   1.- The structure *set* is based on balanced binary tree and its operations work in O(log n) time.
	   2.- The structure *unordered_set* uses hashing, and its operation work in O(1) time on average.
	*/

	cout << "Set: " << endl; 
	set<int> s;
	s.insert(3);
	s.insert(2);
	s.insert(5);
	cout << s.count(3) << "\n"; // 1
	cout << s.count(4) << "\n"; // 0
	s.erase(3);
	s.insert(4);
	cout << s.count(3) << "\n"; // 0
	cout << s.count(4) << "\n"; // 1

	// A set can be used mostly like a vector but it is not possible to access the elements using the [] notation.

	cout << "\n" << "Set like a vector: " << endl;
	set<int> z = {2,5,6,8};
	cout << "Size set<int> z: " << z.size() << "\n"; // 4
	for(auto x : z){
		cout << x << "\n";
	}

	set<int> p;
	p.insert(5);
	p.insert(5);
	p.insert(5);
	cout << p.count(5) << "\n"; // 1

	// C++ also contains the structures multiset and unordered_multiset that otherwise work like set and unordered_set but they 
	// can contain multiple instances of an element.

	cout << "\n" << "Multiset: " << endl;
	multiset<int> e;
	e.insert(5);
	e.insert(5);
	e.insert(5);
	cout << e.count(5) << "\n";

	e.erase(5);
	cout << e.count(5) << "\n";

	// only one instance should be removed
	e.erase(e.find(5)); 
	cout << e.count(5) << "\n"; // 2

	return 0;
}