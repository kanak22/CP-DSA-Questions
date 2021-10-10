// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    bool isPalin(string s, int i, int j)
    {
        while(i <= j)
        {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
    void solve(string &s, vector<vector<string>> &res, vector<string> &v, int i)
    {
        if(i == s.length())
        {
            res.push_back(v);
            return;
        }
        for(int j = i ; j < s.length() ; j++)
        {
            if(isPalin(s, i, j))
            {
                v.push_back(s.substr(i, j - i + 1));
                solve(s, res, v, j+1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string s)
    {
        // code here
        vector<vector<string>> res;
        vector<string> v;
        solve(s, res, v, 0);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends
