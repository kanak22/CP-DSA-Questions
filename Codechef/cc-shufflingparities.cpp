#include<bits/stdc++.h>
using namespace std;
int main()
{   int t;
    cin>>t;
    while(t--)
    {  
        int n;
        cin>>n;
        int a[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int e=0,o=0;
        for (int i = 0; i < n; i++)
        {
            if(a[i]%2==0)
            e++;
            else
            o++;
        }
        int ne=n/2;
        int no=n-ne;
        cout<<min(e,no)+min(o,ne)<<endl;
        
    }
  return 0;
}