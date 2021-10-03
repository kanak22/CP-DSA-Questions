// leetcode question: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

/* 
    This problem can be solved using Binary Search
    We first need to determine where the pivot is in the array 
    The very next element to the pivot is our minimum element
*/

class Solution {
    public int findMin(int[] nums) {
        int pivot = findPivot(nums);
        if(pivot==nums.length-1) return nums[0];
        else return nums[pivot+1];
    }
    
    static int findPivot(int[] arr){
        int start = 0;
        int end = arr.length-1;
        int mid = 0;
        while(start<=end){
            mid = start + (end-start) / 2;
            // case 1
            if(mid<end&&arr[mid] > arr[mid+1]) return mid; // check for pivot
            // case 2
            if(mid>start&&arr[mid-1] > arr[mid]) return mid - 1; // check for pivot
            // case 3
            if(arr[start]==arr[mid]&&arr[mid]==arr[end]){ // to handle duplicate elements
                if(start<end && arr[start] > arr[start+1]) return start; // check if the start is the pivot
                start++;
                if(end>start && arr[end] < arr[end-1]) return end-1; // check if end is the pivot
                end--;
            }
            // case 4
            else if(arr[start] > arr[mid]) end = mid - 1; // if element at mid is less than the start element then pivot lies in the left half hence update end = mid - 1
            // case 5
            else start = mid + 1 ; // else pivot lies in the right half update start = end + 1
        }
        return -1;
    }
}