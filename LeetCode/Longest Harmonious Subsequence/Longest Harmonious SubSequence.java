public class LongHarSubSeq{

    /**
    We define a harmonious array as an array where the difference between its maximum value and its minimum value 
    is exactly 1.

    Given an integer array nums, return the length of its longest harmonious subsequence among 
    all its possible subsequences.

    A subsequence of array is a sequence that can be derived from the array by deleting 
    some or no elements without changing the order of the remaining elements.

    Sample Input: nums = [1,3,2,2,5,2,3,7]
    Sample Output: 5 
    Explanation: The longest harmonious subsequence is [3,2,2,2,3].
     */


     // ******************** Solution *******************
     /**
     In this solution, we are using a two-pointer approach to solve the problem in one traversal. 

     At worst, the solution will take two traversal of the array that is O(2*n) which means --> 
     Time complexity: O(n)
     Space complexity: O(1)

     Since, we are not using any extra space to solve the problem. 
      */

    public int findLHS(int[] nums) {
        // at first we have to sort the array 
        // the very idea of sorting it first is that, if
        // we sort it then only in one traversal we will be able to solve and get all the subsequence
        // If we sort, and move pointers then we can be sure that , the previous pointers do 
        // not have any possibility of being an answer to our question. 
        Arrays.sort(nums);
        
        // variables
        int i = 0, j = 1, len = 0;
        
        // run a while loop until j reaches the end of the array
        while(j<nums.length){
            
            // case when our required condition is met 
            if(nums[j]-nums[i] == 1){
                j++;
                len = Math.max(len, j-i);
                
            }
            
            // case when the difference is greater
            else if(nums[j]-nums[i] > 1){
                // len = Math.max(len, j-i);
                i++;
            }
            
            // if the above case is true then at some point i=j 
            // at the point, we need to increment the value of j 
            // to move to next
            else if(j-i == 0)
                j++;
            
            // at times, we will have same elements 
            // incrementing j will increase the length
            else if(nums[j]-nums[i] == 0)
                j++;
            
        }
        
        return len;
    }


    public static void main(String[] args){

    }
}