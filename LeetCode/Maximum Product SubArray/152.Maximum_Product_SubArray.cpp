/*
This is 22nd Question listed in the 450 DSA questions sheet in Arrays
It is also a variation of Kadane's Algorithm

152.Maximum Product SubArray

Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

It is guaranteed that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

Link: -  https://leetcode.com/problems/maximum-product-subarray/

 */

#include "bits/stdc++.h"

class Solution
{
public:
    int maxProduct(vector<int> nums)
    {
        if (nums.size() == 0)
            return 0;

        int ans = INT_MIN, maxProd = 1, minProd = 1;

        for (int n : nums)
        {
            if (n < 0)
                swap(maxProd, minProd); // Swap max and min beacause if the number is less than zero then the negative values will become positive and vice versa
            // Reset to current value if smaller or larger than it
            maxProd = max(maxProd * n, n);
            minProd = min(minProd * n, n);
            // Update the best
            ans = max(ans, maxProd);
        }

        return ans;
    }
};