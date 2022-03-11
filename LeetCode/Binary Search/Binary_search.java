//Question link:https://leetcode.com/problems/binary-search/

class Solution {
    public int search(int[] nums, int target) {
        int start=0;               //intialising start as 0
        int end=nums.length-1;     //initialising end as length of array nums-1
        
        while(end>=start){
            int mid=start+(end-start)/2;    //assigning mid the middle the average of start and end
            if(target==nums[mid]){
                return mid;                //the index mid is returned if the number is found
            }
            if(target>nums[mid]){
                start=mid+1;
            }
            if(target<nums[mid]){
                end=mid-1;
            }
        }
        return -1;   //if the number is not found, -1 is returned
    }
}
