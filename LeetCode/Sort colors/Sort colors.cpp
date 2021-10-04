    // THIS CAN ALSO BE SOLVED USING COUNTING SORT O(N) BUT IN 2 PASS(see hints for this).
    
    // THIS IS DUTCH NATIONAL FLAG ALGORITHM.  O(N) in one pass!
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while(mid <= high) {
            // if nums[mid] == 0.
            if(nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            // if nums[mid] == 1.
            else if(nums[mid] == 1) {
                mid++;
            }
            // if nums[mid] == 2.
            else if(nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        return;
    }