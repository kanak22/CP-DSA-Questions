// CYCLIC SORT is used.
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), ans = n + 1;
        for(int i = 0; i < n; ) {
            // don't forget this condition else TIME LIMIT EXCEEDED error will be thrown.
            if(nums[i] <= 0 || nums[i] > n || nums[i] == nums[nums[i] - 1])
                i++;
            else if(nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                ans = i + 1;
                break;
            }
        }
        return ans;
    }