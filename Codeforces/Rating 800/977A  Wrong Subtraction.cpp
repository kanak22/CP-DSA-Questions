#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n,k;
  cin>>n>>k;
  
  int i=0;
  while(i<k)
  {
      if(n%10==0)
      {
          n=n/10;
      }
      else{
          n=n-1;
      }
      i++;
  }
  cout<<n<<endl;
    return 0;
}