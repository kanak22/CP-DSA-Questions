class Solution {
public:
    int findMin(vector<int>& nums) {
        int r = nums.size()-1, l = 0, mid;
        if (!r) 
            return nums[0]; // only one element

        while (l < r)
        {
            mid = l + (r - l) / 2;

            // got a part that is not rotated
            if (nums[l] < nums[r]) 
                return nums[l]; 

            // mid is larger than right - min is in right side
            else if (nums[mid] > nums[r]) 
                l = mid + 1;

            // mid is smaller than right - min is in left side (including mid)
            else 
                r = mid;
        }
        return nums[l];
    }
};
