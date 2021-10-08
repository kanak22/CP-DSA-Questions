// leetcode question : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

/* 
    This qyestion can be solved using Binary Seach

    Step 1: find the left most position of the element -> this is the first position
        Approach: We look for the target using binary search : once we encounter the target
                  we mark it as a  potential ans (we store it as ans[0] = mid) and we look if there are other more occurences in the
                  left half by doing end = mid - 1 as the goal of this half is to find the leftmost occurence of the target.

    Step 2: find the right most position of the element -> this is the last position
        Approach: It is very similar to the approach in step 1, the only difference is that instead of searching in the left half we search in the 
                  right half. So once we encounter the target we store it as a potential ans(by storing it as ans[1] = mid) and we look in 
                  the right half for more occurences as the goal is to find the right most position

*/

class Solution {
    public int[] searchRange(int[] arr, int target) {
        int[] ans = {-1,-1}; // initialzing in case the target dosen't exixts 
        int start = 0;
        int end = arr.length-1;
        int mid = 0;
        // searching fot the left most target (Step 1)
        while(start<=end){
            mid = start + (end-start) / 2;
            if(arr[mid]>target) end = mid - 1;
            else if(arr[mid]<target) start = mid + 1;
            else {
                ans[0] = mid; // potential ans
                end = mid - 1; // also look for better ans in the left half
            }
        }
        // reinitializing for another round of binary search
        start = 0; 
        end = arr.length-1;
        // searching for the right most target (step 2)
        while(start<=end){
            mid = start + (end-start) / 2;
            if(arr[mid]>target) end = mid - 1;
            else if(arr[mid]<target) start = mid + 1;
            else {
                ans[1] = mid; // potential ans
                start = mid + 1; // also look for better ans in the right half
            }
        }
        return ans; // return the ans
    }
}