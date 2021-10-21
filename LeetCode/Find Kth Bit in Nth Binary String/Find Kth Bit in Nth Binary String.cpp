class Solution {
public:
    // string reverse(string s){
    //     string ans="";
    //     for(double i=0; i<s.length();){
    //         ans+=s[s.length()-i-1];
    //         i=i+1;
    //     }
    //     return ans;
    // }
    // string invert(string s){
    //     string ans="";
    //     for(double i=0; i<s.length();){
    //         if(s[i]=='0') ans+='1';
    //         else ans+='0';
    //         i=i+1;
    //     }
    //     return ans;
    // }
    // string solve(int n){
    //     if(n==1) return "0";
    //     else return solve(n-1)+"1"+reverse(invert(solve(n-1)));
    // }
    // char findKthBit(int n, int k) {
    //     string solution=solve(n);
    //     return solution[k-1];
    // }
    char findKthBit(int n, int k) {
         string s="0";//S1
        string s1;
        while(n--){
            s1=s;
            reverse(s1.begin(),s1.end());//reverses the binary number
            // for(double i=0; i<s1.length();){
            //     if(s1[i]=='0') s[i]='1';
            //     else s1[i]='0';
            //     i=i+1;
            // }
            for(char &c: s1){
                if(c=='0') c='1'; else c='0';//inverts the binary number
            }
            s+="1"+s1;//finally adds 1 to it
        }
        return s[k-1];
    }
};
