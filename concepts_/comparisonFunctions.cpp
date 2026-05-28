#include <bits/stdc++.h>

using namespace std;

int main(){

	bool comp(string a, string b){
		if(a.size() != b.size()) return a.size() < b.size();
		return a < b;
	}

	sort(v.begin(), v.end(), comp);

	return 0;
}