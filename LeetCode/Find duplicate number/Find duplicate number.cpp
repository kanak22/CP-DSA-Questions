int findDuplicate(vector<int>& nums) {
        // This solution can also be solved using floyd's method without changing vector.

        // This is CYCLIC SORT.
        int n = nums.size(), ans;
        for(int i = 0; i < n; ) {
            if(nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
            else 
                i++;
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }