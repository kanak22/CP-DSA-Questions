// c++ program for reversing an array

#include<bits/stdc++.h>
using namespace std;
int main() {

	// taking input the number of elements in the array
	int n;
	cin>>n;

	// taking input the elemets of the array
	int arr[n+1];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}


	// printing the original array
	cout<<"original array is: "<<endl;
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	// initializing the start and end point of the array
	int start = 0, end = n-1;

	// loop till start<=end
	while(start<=end) {

		// swap the value at start and value at end index
		swap(arr[start], arr[end]);

		// increment start
		start++;

		// decrement end
		end--;

	}


	// printing the reversed array
	cout<<"reversed array is: "<<endl;
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
