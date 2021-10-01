/*
Reverse an Array using
1. Conventional For Loop
2. Recursion

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include<iostream>
using namespace std;

void reverseArray(int arr[], int n) {
    int temp;
    for(int i=0, j=n; i<=j; i++, j--) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void recursionReverse(int arr[], int start, int end) {
    int temp;
    if(start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        recursionReverse(arr, start+1, end-1);
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int temp, arr[5]={1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Original Array: ";
    printArray(arr, n);

    reverseArray(arr, n-1);
    cout<<"\nReversed Array: ";
    printArray(arr, n);

    cout<<"\nRecursion Reversed Array: ";
    recursionReverse(arr, 0, n-1);
    printArray(arr, n);
    return 0;
}