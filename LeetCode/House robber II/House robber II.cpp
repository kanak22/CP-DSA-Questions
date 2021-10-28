/*
Link of the question:
https://leetcode.com/problems/house-robber-ii/


You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. 
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        // if there is only one house then simply rob that house.
        if(n==1)
        {
            return nums[0];
        }
        // if there are two houses then rob the max house.
        if(n==2)
        {
            return max(nums[0],nums[1]);
            
        }
         // if there are three houses in a circle you can only rob one so rob the max out of the 3.
        if(n==3)
        {
            int c=max(nums[0],nums[1]);
            return max(c,nums[2]);
        }
        //maintain a dp1 array which will start from house 0.
        int dp1[n-1];
        dp1[0]=nums[0];
        dp1[1]= max(nums[0],nums[1]);
         //maintain a dp2 array which will start from house 1.
        int dp2[n];
        dp2[1]=nums[1];
        dp2[2]= max(nums[1],nums[2]);
        // a loop from i=2 to n-1 for dp array 1.
        for(int i=2;i<n-1;i++)
        {
            // check if i-2th house + ith house value greater than i-1th house
            if(dp1[i-2]+nums[i]>dp1[i-1])
            {
                dp1[i]=dp1[i-2]+nums[i];
            }
            else
            {
                dp1[i]=dp1[i-1];
            }
        }
         // a loop from i=3 to n for dp array 1.
        for(int i=3;i<n;i++)
        {
            // check if i-2th house + ith house value greater than i-1th house
             if(dp2[i-2]+nums[i]>dp2[i-1])
            {
                dp2[i]=dp2[i-2]+nums[i];
            }
            else
            {
                dp2[i]=dp2[i-1];
            }
        }
        // return max of dp1[n-2] and dp2[n-1]
        return max(dp1[n-2],dp2[n-1]);
    }
};