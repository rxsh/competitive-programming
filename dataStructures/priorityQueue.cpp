#include <bits/stdc++.h>

using namespace std;

int main(){

	/*
	A priority queue maintains a set of elements. The supported operations are insertion and, depending on the type of the queue,
	retrieval and removal of either the minimun or maximun element.
	Insertion and removal take O(log n) time, and retrieval takes O(1) time.
	*/

	priority_queue<int> q;
	q.push(3);
	q.push(5);
	q.push(7);
	q.push(2);
	cout << q.top() << "\n"; // 7
	q.pop();
	cout << q.top() << "\n"; // 5
	q.pop();
	q.push(6);
	cout << q.top() << "\n"; // 6
	q.pop();

	/*
	If we want to create a priority queue that supports finding and removing the smallest element, we can do it as follows:
	*/

	cout << "\n" << "priority_queue remove the smallest element: " << "\n";
	priority_queue<int,vector<int>,greater<int>> p;
	p.push(3);
	p.push(5);
	p.push(7);
	p.push(2);
	cout << p.top() << "\n"; // 2 
	p.pop();
	cout << p.top() << "\n"; // 3
	p.pop();
	p.push(4);
	cout << p.top() << "\n"; // 4
	p.pop();

	return 0;
}