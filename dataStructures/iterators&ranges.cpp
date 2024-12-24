#include <bits/stdc++.h>

using namespace std;

int main(){

	/*
	An iterator is a variable that points to an element in a data structure.
	The often used iterators begin and end points to the first element in the data structure, and the iterator end points
	to the position after the last element.
	
	{ 3, 4, 6, 8, 12, 13, 14, 17 }
	s.begin() -> 3
	s.end() -> }

	Note the asymmetry in the iterators: s.begin() points to an element in the data structure, while s.end() points outside
	the data structure. Thus, the range defined by the iterators is half-open
	

	- Working with ranges

	Usually, we want to process all elements in a data structure, so the iterators begin and end are given for the function.
	The following code sorts a vector using the function sort, then reverses the order of the elements using the function reverse,
	and finally shuffles the order of the elements using the function random_shuffle
	*/

	sort(v.begin(), v.end())
	reverse(v.begin(), v.end())
	random_shuffle(v.begin(), v.end())

	// The functions can also be used with an ordinary array. In this case, the functions are given pointers to the array instead of iterators:

	sort(a,a+n);
	reverse(a,a+n);
	random_shuffle(a,a+n);

	return 0;
}