#include <bits/stdc++.h>

using namespace std;

int main()
{
   string s1,s2;
   cin>>s1>>s2;
   
   int flag=0;
   reverse(s1.begin(),s1.end());
   
   if(s1==s2){
       flag=1;
   }
   
   if(flag==1)
   {
       cout<<"YES"<<endl;
   }
   else{
       cout<<"NO"<<endl;
   }
   return 0;
}