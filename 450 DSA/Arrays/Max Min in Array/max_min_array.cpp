/*
Find Max and Min elements in an Array

Time Complexity: O(N)
*/

#include<iostream>
using namespace std;

struct Pair
{
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int n) {
    struct Pair P;
    if(n==1) {
        P.min = P.max = arr[0];
        return P;
    }

    if(arr[0] > arr[1]) {
        P.min = arr[1];
        P.max =  arr[0];
    }
    else {
        P.min = arr[0];
        P.max = arr[1];
    }

    for(int i=2; i<n; ++i)
        if(arr[i] < P.min)
            P.min = arr[i];
        else if(arr[i] > P.max)
            P.max = arr[i];

    return P;
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}

int main() {
    int arr[5] = {21, 5, 9, 2, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Original Array: ";
    printArray(arr, n);

    struct Pair P = getMinMax(arr, n);
    cout<<"\nMin Value: "<<P.min;
    cout<<"\nMax Value: "<<P.max;

    return 0;
}