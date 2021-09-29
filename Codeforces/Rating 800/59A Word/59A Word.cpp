#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  cin>>s;
  int countU,countL;
  countU=countL=0;
  for(int i=0; i<s.size(); i++){
      if(isupper(s[i]))
      {
          countU++;
      }
      else{
          countL++;
      }
  }
  if(countU>countL)
  {
      transform(s.begin(),s.end(),s.begin(), ::toupper);
  }
  else
  {
      transform(s.begin(),s.end(),s.begin(), ::tolower);
  }
  cout<<s<<endl;
    return 0;
}