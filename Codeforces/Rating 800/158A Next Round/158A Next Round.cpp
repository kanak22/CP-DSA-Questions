#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n],count=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n; i++)
    {
        if(a[i]>0 && a[i]>=a[k-1])
        {
            count++;
        }
    }
    
    cout<<count<<endl;
    return 0;
}
