
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size();
    int a[n];
    for(int i=0; i<n; i++){
        if(s1[i]!=s2[i]){
            a[i]=1;
        }
        else{
            a[i]=0;
        }
    }
    for(int i=0; i<n; i++){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
    
}