// leetcode question : https://leetcode.com/problems/split-array-largest-sum/

// This Problem can be solved using Binary Search
/*
    Binary Search might not be the first idea that pops up in someone head to approach this 
    solution. 
    The part where we use Bianry Search in determining the minimum sum that is the largest amongst the m subarrays
    Step 1: The least sum that is largest amongst the subarrays occurs when the array is split into individual elememts and then the largest sum the the largest number in the array 
            and since we cannot furthur divide a subarray with one element this is the least value of sum when the array is divided 
            Hence this is our start pointer
            TLDR: start pointer is the largest number in the subarray

    Step 2: The maxmimun sum in the subarray occurs when the array is split into o parts i.e the original array , here the largest sum is the sum of all the elements
            And since all the elements are summed in this case this is the largest possible sum
            Hence this is our end pointer
            TLDR: end pointer is the sum of all the elements in the array 
    
    Step 3: The mid pointer : start + (end-start) / 2

    Step 4: We now perform a simple binary search and keep track of the number of subarays that are generated 
            If the number of subarrays is more than the target it means that our mid is small and hence it's generating more subarrays 
            to fix this we simply need to increase our current sum by moving the start pointer to mid + 1
    
    Step 5: Else its a potential Answer and we can look for more optimized answer

    Step 6: In the end both start and end pointers point at the optimal solution 

*/

class Solution {
    public int splitArray(int[] nums, int m) {
        int start = nums[0]; // max in array
        int end = nums[0]; // sum of all elements in the array
        for(int i=1;i<nums.length;i++){
            start = Math.max(start,nums[i]);
            end += nums[i];
        }
        while(start < end){
            int mid = start + (end-start) / 2;
            int fragments = 1; // to keep track of the no of subarrays the minimum can be 1
            int currSum = 0; // to keep track of the sum in the subarray
            for(int num : nums){
                if(currSum + num > mid){ // if the sum in the subarray exceeds the mid value we increase the no of subarrays by doing ++fragments
                    currSum = num; // and assing the sum of the new subarray as its first element
                    ++fragments;
                }else currSum += num;
            }
            if(fragments > m) start = mid + 1; // check if the number of subarrays exceeds the target or not ? increse the mid pointer by doing start = mid + 1 : its a potential ans but look for better solution by doing end = mid (our job is to find the minimum sum)
            else end = mid;
        }
        // the loop breaks when start and end point at the optimal solution 
        return start;
    }
}