#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string s;
    cin>>s;
    char ch=toupper(s[0]);
    s = s.substr(1, s.size() - 1);
    cout<<ch<<s<<endl;
    return 0;
}