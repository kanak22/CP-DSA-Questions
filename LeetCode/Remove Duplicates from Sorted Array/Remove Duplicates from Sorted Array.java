class Solution {
    public int removeDuplicates(int[] nums) {  //input a nums array

        //if nums is invalid or 0, give 0
        if (nums == null || nums.length == 0) {
            return 0;
        }
        
        int i = 0;  //i is a counter variable
        
        //iterating over the array
        for (int j = 0; j < nums.length; j++) {

            //if number at j index is not equal to number at i index(inital value 0)
            if (nums[j] != nums[i]) {
                //increment i
                i++;

                //number at incremented i index to be set equal to number at j index
                nums[i] = nums[j];
            }            
        }
        
        //exit the loop to return i+1
        return i + 1;
        
    }
}