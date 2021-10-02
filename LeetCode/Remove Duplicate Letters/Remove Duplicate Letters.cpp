/*
Author : Neenad Kambli
Problem Url : https://leetcode.com/problems/remove-duplicate-letters/
*/


class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans; // ans string variable to store our result
        int n = s.length();
        vector<int> lastPos(26,-1); 
        vector<bool> visited(26,false);
        // lastPos is a vector of size 26 to track the last position in string s 
        //of lowercase alphabets
        //we can take size of vector as 256 if our input is not limited to lowercase letters
        // vector visited is to keep track of duplicate characters
        vector<char> arr; // vector arr acts like a stack of characters
        
        for(int i=n-1;i>=0;i--){ // tracking last pos of distinct characters in input string
            if(lastPos[s[i]-'a'] == -1){
                lastPos[s[i]-'a'] = i;
            }
        }
        
        // here the logic is pop the last character(arr.back()) if it is not 
        // visited and it is lexicographically greater than current character(s[i])
        // and also it will be added later which can be checked using lastPos vector
        // for eg s = bcabc arr = [b,c] current char = a now c and b can be popped
        // because b and c are lexicographically smaller than a and b and c will
        // appear later on in the input string and mark the popped character as not
        // visited also later add the current character only if it is duplicated i.e  
        // visited[s[i]-'a'] should be false 
        
        for(int i=0;i<n;i++){
            while(arr.size() > 0 && arr.back() > s[i] && !visited[s[i]-'a'] && lastPos[arr.back()-'a']>i){
                visited[arr.back()-'a'] = false;
                arr.pop_back();
            }
            
            if(visited[s[i]-'a'] == false){
                visited[s[i]-'a'] = true;
                arr.push_back(s[i]);
            }
        }
        
        for(char &c : arr){
            ans+=c; // finally appending all distinct characters in arr to ans variable
        }
        
        return ans;
    }
};