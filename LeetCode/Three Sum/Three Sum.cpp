class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if(n < 3)
            return res;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int a = nums[i];
            // The sum is 0. Hence, at least, the smallest number has to be negative.
            if(a > 0) return res; 

             // Apply 2 pointer approach on each such a
            int low = i+1, high = n-1;
            while(low < high){
                int b = nums[low], c = nums[high];
                if(a + b + c == 0){
                    res.push_back({a, b, c});
                    while(low < high && nums[low] == nums[low+1]) low++;
                    while(low < high && nums[high] == nums[high-1]) high--;
                    low++; high--;
                }
                else if(a + b + c < 0)
                    low++;
                else
                    high--;
            }
        }
        return res;
    }
};