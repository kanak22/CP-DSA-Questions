// Question : https://leetcode.com/problems/ugly-number/

// Example
/**
 * Input  : n = 7
 * Output : 8
 *
 * Input  : n = 10
 * Output : 12
 *
 * Input  : n = 15
 * Output : 24
 */

// Solution
class Solution {
   public static boolean isUgly(int n) {
       if(n <= 0)
           return false;

       while(n > 1) {

           if(n % 2 == 0)
               n /= 2;
           else if(n % 3 == 0)
               n /= 3;
           else if(n % 5 == 0)
               n /= 5;
           else
               return false;
       }

       return true;
   }

   public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       int n = sc.nextInt();

       System.out.println( isUgly(n) );
   }
}

// Time Complexity : <=O(log n/2)
// Space Complexity : O(1)