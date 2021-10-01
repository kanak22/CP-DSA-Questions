/*
Kth Smallest Element in an Array using
Built-in sort() which works on "INTROSORT" algorithm

Time Complexity: O(N*Log(N))
*/

#include<iostream>
#include<algorithm>
using namespace std;

int partitionArray(int arr[], int pivot, int start, int end) {
    int i = start;
    int j = end;

    while(i < j) {
        while(arr[i] <=pivot)
            i++;
        while(arr[j] > pivot)
            j--;

        if(i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[start], arr[j]);
    return j;
}

int quickSelect(int arr[], int start, int end, int k) {
    int pivot = arr[end];
    int pi = partitionArray(arr, pivot, start, end);

    if(k > pi)
        return quickSelect(arr, pi, end, k);
    else if( k < pi)
        return quickSelect(arr, start, pi+1, k);
    else
        return arr[pi];

}

int Kth_Smallest_Element(int arr[], int size, int k) {
    sort(arr, arr+size);
    return arr[k-1];
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main() {

    int arr[7] = {10, 4, 8, 2, 5, 10, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout<<"Original Array: ";
    printArray(arr, n);

    cout<<endl<<k<<" smallest element: "<<quickSelect(arr, 0, n-1, k-1);

    return 0;
}