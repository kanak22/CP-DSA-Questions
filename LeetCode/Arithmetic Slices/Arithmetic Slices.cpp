/*
Question Link: https://leetcode.com/problems/arithmetic-slices/

An integer array is called arithmetic if it consists of at least
three elements and if the difference between any two consecutive
elements is the same.

*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int i,j,k,n=A.size();
        if(n<=2)
            return 0;
        int dp[n];

        // Let dp[i] = number of arithmetic slices ending with ith element of array

        memset(dp,0,sizeof(dp));
        for(i=2;i<n;i++)
        {
            if(A[i]-A[i-1]==A[i-1]-A[i-2])
            {
                dp[i]=1+dp[i-1];
                // If A[i-2], A[i-1] & A[i] form an AP, then number of
                // Arithmetic progressions ending at position i is
                // greater than the number of arithmetic progressions
                // ending at position i-1 by 1.
            }
        }
        int f=0;

        //We count all the slices present in the array
        for(i=2;i<n;i++)
            f=f+dp[i];
        return f;
    }
};


//Time Complexity : O(N), where N = size of given array
//Space Complexity : O(N), Because we used dp array to store number of APs ending at ith position.
