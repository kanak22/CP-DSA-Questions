/*APPROACH TOWARDS THE SOLUTION
---------------------------------------------------------------------------------------------------------------------------------------------

1. This is a problem wherein a simple for loop with two "pointers" will work well. Note that the problem requires the relative order.

2. The idea is to set two pointers, one for zeros, one for numbers (non-zero numbers), all start from 0. 

3. Every time we meet zero value, then we swap the values of the pointers, and go to next value in the array. 

4. In this way, after a whole loop through the array, zeroes are swapped into the end while the relative order of other numbers is still kept.

*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        int tmp;
        for (int i=0;i<nums.size();++i){
            if (nums[i] != 0){
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                j++;
            }
        }
    }
};
