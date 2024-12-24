#include<bits/stdc++.h>

using namespace std;

int main(){

	// Dynamic arrays: Is an array whose size can be changed during the execution of the program.

	vector<int> v;
	v.push_back(3); // [3]
	v.push_back(2); // [3,2]
	v.push_back(5); // [3,2,5]

	cout << v[0] << "," << v[1] << "," << v[2] << endl; 

	for(int i=0; i < v.size(); i++){
		cout << v[i] << "\n";
	}

	for(auto x : v){
		cout << x << "\n";
	}

	vector<int> b;
	b.push_back(5);
	b.push_back(2);
	cout << b.back() << "\n"; // 2
	b.pop_back();
	cout << b.back() << "\n"; // 5

	vector<int> p = {5,3,10,2,4};

	// size 10, initial value 0
	vector<int> l(10);
	// size 10, initial value 5
	vector<int> k(10,5);

	string a = "hatti";
	string c = a+a;
	cout << c << "\n"; // hattihatti
	c[5] = 'v';
	cout << c << "\n"; // hattivatti
	string d = c.substr(3,4);
	cout << d << "\n"; // tiva


	return 0;
}