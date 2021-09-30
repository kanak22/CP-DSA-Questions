#include <bits/stdc++.h>

using namespace std;

int main()
{
   int a,b,count=0;
   cout<<"enter two numbers consecutively";
   cin>>a>>b;
   while(a<=b)
   {
       count++;
       a=a*3;
       b=b*2;
   }
   cout<<count<<endl;
    return 0;
}
