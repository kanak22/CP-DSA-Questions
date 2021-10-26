/*Question Link : https://leetcode.com/problems/long-pressed-name/ */


// Your friend is typing his name into a keyboard. Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

// You examine the typed characters of the keyboard. Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

 
/*
Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true
Example 4:

Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.
 

Constraints:

1 <= name.length <= 1000
1 <= typed.length <= 1000
name and typed contain only lowercase English letters.

*/

// Solution 


class Solution {
public:
    bool isLongPressedName(string a, string b) {
        int n=a.length(); // length of a string 
        int l=b.length();  //lenght of string b 
        if(n>l) return false;  // invalid string 
        int i=0,j=0; // intialise i and j 

        while(i<n){ //run loop till i<n 
            if(a[i]==b[j]){  // if a[i]==b[j] then increment i and j 
                i++;
                j++;
            }
            else if(i>0 && (a[i-1]==b[j])){  
             //if current inex of b is not equal to current index of string a then check
            // whether is it equal to previous index of string a ,it means that it will be long pressed 
            //then keep incrementing j 
                j++;
            }
            else{
                return false;
            }
        }
        while(j<l){  //if last index of j string is long pressesd
            if(b[j]!=a[n-1]) return false;
            j++;
}
        return true;
    }
};