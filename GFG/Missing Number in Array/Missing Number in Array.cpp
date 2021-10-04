/*

Question Link : https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1
Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

Example 1:

Input:
N = 5
A[] = {1,2,3,5}
Output: 4

*/
int MissingNumber(vector<int>& array, int n) {
        int TotalSum = (n*(n+1))/2;
        int i,sumObtain=0;
        for(i=0;i<n-1;i++)
        {
            sumObtain += array[i];
        }
        return TotalSum-sumObtain;
    }
