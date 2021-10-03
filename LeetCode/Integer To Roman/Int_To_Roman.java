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
public class Int_To_Roman {
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
        int div = 1000;
        
        // StringBuilder to store the final answer.
        StringBuilder ans = new StringBuilder("");
        
        
        while(A>0){
            int count = A/div;
            if(count == 4){
                ans.append(map.get(div)).append(map.get(5*div));
            }
            else if(count == 5){
                ans.append(map.get(5*div));
            }
            else if(count == 9){
                ans.append(map.get(div)).append(map.get(10*div));
            }
            else{
                if(count <= 3){
                    while(count-->0){
                        ans.append(map.get(div));
                    }
                }
                else if(count > 5 && count < 9){
                    ans.append(map.get(5*div));
                    count -= 5;
                    while(count-->0){
                        ans.append(map.get(div));
                    }
                }
            }
            A = A%div;
            div /= 10;
            
        }
        return ans.toString();
    }
}
