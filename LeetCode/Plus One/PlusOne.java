class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 1;
        for (int i = digits.length - 1; i >= 0 && carry == 1; i--) {
            int temp = digits[i] + carry;
            if (temp >= 10) {
                carry = 1;
                digits[i] = temp % 10;
            } else {
                carry = 0;
                digits[i] = temp;
            }
        }
        if (carry != 0) {
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