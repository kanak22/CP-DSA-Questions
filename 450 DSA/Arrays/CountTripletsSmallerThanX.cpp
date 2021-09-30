#include<bits/stdc++.h>
using namespace std;

int count(int arr[], int n, int val) 
{ 
    sort(arr, arr+n);  
    int cnt = 0; 
  
    for (int i = 0; i < n - 2; i++) 
    { 
        int left_ind = i + 1, right_ind = n - 1; 
        while ( left_ind < right_ind ) 
        { 
              int sum = arr[i] + arr[left_ind] + arr[right_ind];
            if ( sum >=val ) 
                right_ind--; 
            else
            { 
                 cnt += (right_ind - left_ind); 
                left_ind++; 
            } 
        } 
    } 
    return cnt; 
} 
int main() 
{ 
    int arr[] = {5, 1, 3, 4, 7}; 
    int n = sizeof arr / sizeof arr[0]; 
    int sum = 12; 
    cout << count(arr, n, sum) << endl; 
    return 0; 
} 