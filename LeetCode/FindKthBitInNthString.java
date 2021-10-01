class Solution {
    public char findKthBit(int n, int k) {
        if (n == 1) {
            return '0'; // as first string will be "0"
        }
        int len = (1 << n) - 1; //as string length increases in 2 to power n-1 fir given n
        if (k == len / 2 + 1) {
            return '1'; //middle character will always be '1'
        } else if (k > len / 2 + 1) {
            return findKthBit(n - 1, len - k + 1) == '0' ? '1' : '0'; //here we check in right of middle and it is reverse of 
            //left part of string so changing k accordingly and whatever result we get we flip it
        } else {
            return findKthBit(n - 1, k); //looking in left part of string
        }
    }
}
