//https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    void swap(vector<int>& nums, int a, int b){//swap two elements in a vector
        int temp=nums[a];//temp is temporary variable
        nums[a]=nums[b];
        nums[b]=temp;
    }
    int findDuplicate(vector<int>& nums) {
        /*sort(nums.begin(), nums.end());
        int start=0, end=nums.size();
        for(int i=1; i<end; i++){
            if(nums[i]==nums[i-1]){
                return nums[i];
            }
        }
        return -1;*/
        int i=0, n=nums.size();
        while(i<n){//pushing the duplicate number to the end of the vector
            if((nums[nums[i]-1]==nums[i])&&(nums[i]!=i+1)){//checking whether number is in right position
                i++;
            }
            else if(nums[nums[i]-1]!=nums[i]){
                swap(nums, i, nums[i]-1);
            }
            else i++;
        }
        return nums[n-1];
    }
};
