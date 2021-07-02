#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
  int n,ca,cd;
  cin>>n;
  string s;
  cin>>s;
  ca=cd=0;
  for(int i=0; i<n; i++)
  {
      if(s[i]=='A')
      {
          ca++;
      }
      else{
          cd++;
      }
  }
  if(ca>cd){
      cout<<"Anton"<<endl;
  }
  else if(ca<cd){
      cout<<"Danik"<<endl;
  }
  else{
      cout<<"Friendship"<<endl;
  }
  
   return 0;
}