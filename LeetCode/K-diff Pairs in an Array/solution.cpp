class Solution {
public:
    bool binarySearch(vector<int>& nums,int start,int end,int target){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target) return 1;
            else if(nums[mid]>target) end=mid-1;
            else start=mid+1;
        }
        return 0;
    }
    int findPairs(vector<int>& nums, int k){
        set<int> s;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n-1; i++){
            if(binarySearch(nums,i+1,n,nums[i]+k)){
                s.insert(min(nums[i],nums[i]+k));
            }
        }
        return s.size();
    }
};