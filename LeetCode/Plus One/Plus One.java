class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 1;
        // start the loop from last index
        for (int i = digits.length - 1; i >= 0 && carry == 1; i--) {
            int temp = digits[i] + carry;
            if (temp >= 10) {  // if number is greater than 10 we will add 1 in carry 
                carry = 1;     // modulus with 10 to get the unit digit
                digits[i] = temp % 10;
            } else {
                carry = 0;      // if not > 10, then carry is zero
                digits[i] = temp;
            }
        }
        if (carry != 0) {   // if carry is not zero, we create new array of size plus one the orignal
            int[] newDigits = new int[digits.length+1];
            newDigits[0] = 1;
            for (int i = 1; i < newDigits.length; i++) {
                newDigits[i] = digits[i-1];
            }
            return newDigits;
        }
        return digits;
    }
}