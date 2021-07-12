#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long long int n,count=0;
    cin>>n;
       if(n % 2 == 0) {
           count = n / 2;
           
       }
    else {
        count = ((n + 1) / 2) * (-1);
    }
    cout<<count<<endl;
}