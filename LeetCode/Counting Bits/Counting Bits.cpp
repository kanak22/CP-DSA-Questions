// Approach: Used Brian Kernighan’s Algorithm for this question.
// Example-   n =  10 (1010)
//    count = 0

//    Since 10 > 0, subtract by 1 and do bitwise & with (9-1)
//    n = 10&9  (1010 & 1001)
//    n = 8
//    count  = 1

//    Since 8 > 0, subtract by 1 and do bitwise & with (8-1)
//    n = 8&7  (1000 & 0111)
//    n = 0
//    count = 2

//    Since n = 0, return count which is 2 now


class Solution {
public:
      
    int countthesetbits(int n){
    int c=0;
        while(n){
            n=n&(n-1);
            c++;
        }
        return c;
    }
    vector<int> countBits(int n) {
       vector<int>result;
        for(int i=0;i<=n;i++)
        {  
    
            result.push_back(countthesetbits(i));
        }
     
        return result;
    }
};