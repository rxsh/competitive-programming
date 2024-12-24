#include <bits/stdc++.h>

using namespace std;

int main(){

	/*
	A stack is a data structure that provides two O(1) time operations: adding an element to the top, and removing an element from the top.
	It is only possible to access the top element of a stack.
	*/

	stack<int> s;
	s.push(3);
	s.push(2);
	s.push(5);
	cout << s.top() << endl; // 5
	s.pop();
	cout << s.top() << endl; // 2


	return 0;
}