//Question Link : https://leetcode.com/problems/binary-search/
class Solution {
    public int search(int[] nums, int target) {
        int start=0;
        int end=nums.length-1;
        //assigning 0 to start and length-1 to end
        while(end>=start){
            int mid=start+(end-start)/2; //mid value is the middle value of the array
            if(target==nums[mid]){
                return mid;   //this will return the mid value
            }
            if(target>nums[mid]){
                start=mid+1;
            }
            if(target<nums[mid]){
                end=mid-1;
            }
        }
        return -1;   //if the number is not found, then -1 will be returned
    }
}
