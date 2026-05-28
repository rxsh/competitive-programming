#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(){

	queue<int> q;
	stack<int> s;

	int size = 20;

	for(int i=0; i<size; i++){
		if(i%2==0){
			s.push(i);
		}
		else{
			q.push(i);
		}
	}

	cout << s.top() << endl;
	cout << q.front();

	return 0;
}
