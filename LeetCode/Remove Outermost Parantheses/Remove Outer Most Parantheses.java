//Problem Link: https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
    public String removeOuterParentheses(String s) {
        //start: to find the opening bracket
        //count: to closing baracket
        int count=0, start=0;
        StringBuilder res= new StringBuilder();
        
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)=='(')
                count++;
            else
                count--;
				
            if(count==0){
                res.append(s.substring(start+1,i));
                start=i+1;
            }
        }
        return res.toString();
    }
}