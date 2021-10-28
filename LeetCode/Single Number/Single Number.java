// Given array ,all number occure two time except one number.find that single number
// a[]=[1,2,3,2,1]

public class Solution {

public int singleNumber(int[] nums) {
    int result = 0;
    ////xor operator gives the single number (it returns 0 when xored with same numbers and the number itself when xored with 0)
    for(int i : nums) {
        result ^= i;
    }
    return result;
}
}

//output for given array=3
//Time Complexity O(n)