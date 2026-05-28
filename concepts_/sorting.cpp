+  #include <bits/stdc++.h>

using namespace std;

int main(){

	vector<int> v = {4,2,5,3,5,8,3};
	sort(v.begin(),v.end());

	sort(v.rbegin(),v.rend());

	int n = 7; // array size
	int a[] = {4,2,5,3,8,3};
	sort(a,a+n);


	string s = "monkey";
	sort(s.begin(),s.end());

	return 0;

}