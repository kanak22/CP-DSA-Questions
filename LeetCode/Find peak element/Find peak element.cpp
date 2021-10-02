// Using simple binary search.
int findPeakElement(vector<int>& nums) {
        int n = nums.size(), s = 0, e = n - 1;
        while(s < e) {
            int mid = (s + e)/2;
            if(nums[mid] < nums[mid + 1])
                s = mid + 1;
            else
                e = mid;
        }
        // here s and e both point to same index.
        return s;
    } 