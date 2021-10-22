class Solution {
public:
// two pointers solution
    string removeOuterParentheses(string s) {
        /* i for traversing the string s, acts as a pointer, 
           j as a pointer, 
           open for number of opening paranthesis, 
           close for number of closing paranthese*/
        int i = 0, j = 0, open = 0, close = 0;
        // ans for storing the answer of the problem
        string ans;
        for(i = 0; i<s.length(); i++){
            if(s[i] == '(') open++;
            else close++;
            
            // if number of opening and closing paranthesis are same
            if(open == close){
                // add the contents inside the primitive string to ans
                ans += s.substr(j+1, i-j-1);
                j = i+1;
            }
        }
        return ans;
    }
};