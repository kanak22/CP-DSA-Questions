/*
This is the 8th Question in the 450 DSA Sheet 
It is an implementation of KAdane's Algorithm.

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4

https://leetcode.com/problems/maximum-subarray/

53. Maximum Subarray
 */

#include "bits/stdc++.h"
class Solution
{
public:
    int maxSubArray(vector<int> &n)
    {
        int sum = 0, maxn = INT_MIN;//creating variables sum for storing the sum and maxn for storing the max of all 
        for (int i = 0; i < n.size(); i++)
        {
            sum = sum + n[i];
            maxn = max(sum, maxn);
            if (sum < 0)//if sum become negative then creating a new sum 
            {
                if (n[i] < 0)
                    sum = 0;
            }
        }
        return maxn;//returning the answer to main function
    }
};