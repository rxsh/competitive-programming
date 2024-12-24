#include <bits/stdc++.h>

using namespace std;

int main(){

	// Bitset -> A bitset is an array whose each value is either 0 or 1. For example:

	bitset<10> s;
	s[1] = 1;
	s[3] = 1;
	s[4] = 1;
	s[7] = 1;
	cout << s[4] << endl; // 1 
	cout << s[5] << endl; // 0

	/* A benefit of using bitsets is that they require less memory than ordinary arrays, because
	each element in a bitset only uses one bit of mermory.
	The following code shows another way to create the above bitset: */

	bitset<10> b(string("0010011010")); // from right to left
	cout << b[4] << endl; // 1
	cout << b[5] << endl; // 0 

	bitset<10> x(string("0010011010"));
	cout << x.count() << endl; // 4

	// The following code shows examples of using bit operations:

	bitset<10> a(string("0010110110"));
	bitset<10> b(string("1011011000"));
	cout << (a&b) << "\n"; // 0010010000
	cout << (a|b) << "\n"; // 1011111110
	cout << (a^b) << "\n"; // 1001101110

	bitset<10> a(string)

	return 0;
}