#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string s1,s2;
    cin>>s1>>s2;
 
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    
    int flag=0;
    int l=s1.length();
    for(int i=0; i<l; i++)
    {
        if(s1[i] > s2[i])
        {
            flag= 1;
            break;
        }
        else if(s1[i]<s2[i])
        {
            flag=-1;
            break;
        }
    }
    cout<<flag<<endl;
    
    
    return 0;
}