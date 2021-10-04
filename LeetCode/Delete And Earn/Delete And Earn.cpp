/*
Approach : since the problem has optimal substructure (result of smaller subproblems can be combined for finding result of bigger subproblems)
and overlapping subproblems (same subproblems being computed again and again), we can use dp.
Here I've solved using Bottom up Approach.
*/


class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        
        //first sort so that we get nums[i] + 1 and nums[i] - 1 adjacent to nums[i], if they exist
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> map;
        
        //group duplicate elements together and store it in different array, with value = number of times they occur * nums[i]
        for(int i = 0; i < n; i++){
            int curr = nums[i], cnt = 1;
            while(i+1 < n && nums[i+1] == curr){
                i++;
                cnt++;
            }
            map.push_back({curr, cnt*curr});
        }
        
        //new size of array (after grouping duplicates)
        n = map.size();

        //dp[i] = maximum value earned till ith index.
        vector<int>dp(n);
        
        //check for base case
        if(n == 1)
            return map[0].second;
        
        dp[0] = map[0].second;
        
        for(int i = 1; i < n; i++){
            int f = map[i].first;
            int s = map[i].second;
            
            //if nums[i] + 1 is present, take max of the two cases as per question
            if(f == map[i-1].first + 1){
                if(i == 1)
                    dp[i] = max(map[i-1].second, s);
                else
                    dp[i] = max(dp[i-2] + s, dp[i-1]);
            }
            //else take current element
            else{
                dp[i] = dp[i-1] + s;
            }
        }
        
        return dp[n-1];
    }
};

//Time Complexity : O(NlogN), where N = size of given array
//Space Complexity : O(N), Because we used dp and map arrays. 
