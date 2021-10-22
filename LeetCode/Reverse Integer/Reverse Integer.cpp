class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {             //loop condition for integer not null        
            int pop = x % 10;        //last digit of the integer obtained
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;    //pop integer inserted in new integer 
        }
        return rev;         //returned the reversed integer
    }
};
