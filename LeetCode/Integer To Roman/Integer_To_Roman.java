/*

Question : https://leetcode.com/problems/integer-to-roman/ 

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

 

Example 1:

Input: num = 3
Output: "III"
Example 2:

Input: num = 4
Output: "IV"
Example 3:

Input: num = 9
Output: "IX"
Example 4:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= num <= 3999
*/

// Code:

// import statements
import java.util.Scanner;
import java.util.HashMap;

// Main class
public class Integer_To_Roman {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number between 1 and 3999");
        int n = sc.nextInt();
        System.out.println(n+ " in Roman literals : " + new Solution().intToRoman(n));
        sc.close();
    }
}
// Solution class
class Solution {
    
    //function to convert integer to roman. 
    public String intToRoman(int A) {
        
        // Map that stores the roman characters corresponding to the decimal numbers.
        HashMap<Integer, Character> map = new HashMap<>();
        map.put(1,'I');
        map.put(5,'V');
        map.put(10,'X');
        map.put(50,'L');
        map.put(100,'C');
        map.put(500,'D');
        map.put(1000,'M');
        
        // Variable set to 1000 to start finding the roman equivalent from left to right.
        // div stores the order and is decremented like 1000 -> 100 -> 10 -> 1.
        int div = 1000;
        
        // StringBuilder to store the final answer.
        StringBuilder ans = new StringBuilder("");
        
        
        while(A>0){
            int num = A/div;
            // suppose num = 4 and div = 100.
            // so to add 400 to our answer we have to print "CD".
            // so this is done by appending value corresponding to div and then 5*div.
            // in above case, this prints : 'C' for 100 followed by 'D' for 5*100.
            if(num == 4){
                ans.append(map.get(div)).append(map.get(5*div));
            }
            // similarly for num = 5, this part simply prints 5*div.
            else if(num == 5){
                ans.append(map.get(5*div));
            }
            // suppose num = 9 and div = 100.
            // so to add 900 to our answer we have to print "CM".
            // so this is done by appending value corresponding to div and then 10*div.
            // in above case, this prints : 'C' for 100 followed by 'M' for 10*100.
            else if(num == 9){
                ans.append(map.get(div)).append(map.get(10*div));
            }
            else{
                // for values of num which are less than 3. We need to print the value of div (num) number of times in the output string.
                // suppose A = 30. So A/10 = num = 3.
                // So we print value of div(which is 'X' beacuse div = 10) three times to make it "XXX" which is roman for 30 .
                if(num <= 3){
                    while(num-->0){
                        ans.append(map.get(div));
                    }
                }
                // if the number is between 5 and 9. Let's say 8.
                // in this case first 'V' is printed which is value of 5.
                // then 'I' is printed (8-5) times.
                else if(num > 5 && num < 9){
                    ans.append(map.get(5*div));
                    num -= 5;
                    while(num-->0){
                        ans.append(map.get(div));
                    }
                }
            }
            // atlast we store the remainder of A/div and the loop continues.
            A = A%div;
            // this statements simply does 1000 -> 100 -> 10 -> 1.
            div /= 10;
            
        }

        // final answer.
        return ans.toString();
    }
}
