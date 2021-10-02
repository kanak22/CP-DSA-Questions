/*



APPROACH TOWARDS THE PROBLEM:
---------------------------------------------------------------------------------------------------------------

1. Firstly, we will be creating and setting two pointers i.e. start and end.

2. Then, Scanning the string from the start to the end. 

3. We will create and set a table tab 't' to store if the character has occurred previously in the string or not.

4. Check if str[end] has occurred in str[start....end-1].

5. If the step 4 is true, compute the current length of the string and compare it to the max length. Also, set table t[str[start]]=false and i++ (increment i). 

6. If str[end] has not occurred in str[atart....end-1], then set table t[str[end]]=true and j++ (increment j). 



*/


class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        
        if(str.size()==0){return 0;}
        if(str.size()==1){return 1;}
        int start=0;
        int end=0;
        int lenmax = 0;
        map<char,bool> t;
        while ( (start<str.size()) && (end<str.size()) ){
            if (t[str[end]]==false){ 
                t[str[end]]=true;
                lenmax = max(lenmax,end-start+1);
                end++; 
            }else if (t[str[end]]==true){
                lenmax = max(lenmax,end-start);
                t[str[start]]=false;
                start++;
            }
        }
        return lenmax;
    }
};