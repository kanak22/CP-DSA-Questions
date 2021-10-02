class Solution {
public:
    int binarysearch(vector<int>nums, int n, int target)
    {
        int low = 0, high = n-1, mid;
        while(low <= high)
        {
            mid = low+(high-low)/2;
            
            if(nums[mid] == target)
                return mid;
            
            //search in left of mid because if nums[low] <= nums[mid], array is sorted in left part and hence we can binary search
            if(nums[low] <= nums[mid])
            {
                if(target >= nums[low] && target <= nums[mid])
                    high = mid -1;
                else 
                    low = mid + 1;
            }
            
            //else search in right side of mid, as that part is sorted
            else
            {
                if (target >= nums[mid] && target <= nums[high])
                    low = mid +1;
                else
                    high = mid -1;
            }
            
        }
        return -1;
        
    }
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();

        //check for base cases
        if(n==0) return -1;
        
        return binarysearch(nums,n,target);
        
    }
};

//Time Complexity : O(logN), where N = size of given array
//Space Complexity : O(1)
