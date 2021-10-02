class Solution {
    public int firstMissingPositive(int[] nums) {
        int y = 0;
        int g = 0;
        //Find the largest number
        for (int k : nums) {
            if ((int)Math.abs(k) > g) g = (int)Math.abs(k);
        }
        //Sort the number for the easy work
        Arrays.sort(nums);
        for (int i = 1; i < g; i++) {//We need to find the smallest POSITIVE so we start at 1
            //To know whether the number is in the array using binary
            int d = Arrays.binarySearch(nums, i);

            if (d < 0) return i;//If it's in the array d is -1
           
        }
        //Return the last element + 1 because the array contains what it needs
        return nums[nums.length - 1] + 1;
    }
}