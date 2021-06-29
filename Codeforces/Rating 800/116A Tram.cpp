#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n,countin=0,capacity=0;
  cin>>n;
  while(n--){
      int a,b;
      cin>>a>>b;
      
     countin-=a;
     countin+=b;
     capacity=max(capacity,countin);
  }
  cout<<capacity<<endl;
    return 0;
}