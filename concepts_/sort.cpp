#include <bits/stdc++.h>

using namespace std;

// simple algorithms for sorting an array work in O(n^2) time.

int main(){

	//bubble sort O(n^2)

	for(int i=0; i<n; i++){
		for(int j=0; j<n-1; j++){
			if(array[j] > array[j+1]){
				swap(array[j], array[j+1]);
			}
		}
	}

	//merge sort O(n log n)
	/*
	1. If a = b, do not do anything, because the subarray is already sorted.
	2. Calculate the position of the middle element: k = b(a+ b)/2c.
	3. Recursively sort the subarray array[a...k].
	4. Recursively sort the subarray array[k +1...b].
	5. Merge the sorted subarrays array[a...k] and array[k +1...b] into a sorted
	subarray array[a...b].
	*/

	// Counting sort O(n)

	



	return 0;
}


