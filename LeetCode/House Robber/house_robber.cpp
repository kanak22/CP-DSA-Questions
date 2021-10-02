/*
Approach : Since, we can either take current element with i-2 elements' maximum or leave current element and go on with i-1 elements' maximum
          we take the maximum of two and get the answer.
          since, the problem has optimal substructure (result of smaller subproblems can be combined for finding result of bigger subproblems)
          and overlapping subproblems (same subproblems being computed again and again), we can use dp.
          Here I've solved using Bottom up Approach.
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        //check base cases
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0], nums[1]);
        }
        
        //dp vector to store our results, dp[i] = maximum amount of money robbed till ith index.
        vector<int>dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        
        //return value stored in last index, which depicts maximum amount of money robbed including all the houses.
        return dp[n-1];
    }
};

//Time Complexity : O(N), where N = size of given array
//Space Complexity : O(N), Because we used dp array.
