#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int a = n-1;
    string s1 = "I hate it";
    string s2 = "I love it";
    
    string s3 = "I hate that";
    string s4 = "I love that";
    
    string s6=" ";
    string s5;
    
    
    if(n==1){
        cout<<s1<<endl;
        return 0;
    }
    for(int i=1; i<n; i++){
        if(i%2==0)
        {s5 += s4 ;}
        else{
            s5 += s3; 
        }
         s5 += s6;
         a--;
    }
    if((n-a)%2==0){
        s5 += s2;
    }else{
        s5 += s1;
    }
    cout<<s5<<endl;
}