#include <bits/stdc++.h>
using namespace std;
int main()
{
    // variable declartion
    int a, b;
    // basic taking input
    cin >> a >> b;
    int min, max=0;

    // condition checking
    if (a < b)
    {
        min = a;
        b-=a;
        if(b>1)
        max = b / 2;
    }
    else
    {
        min = b;
        a-=b;
        if(a>1)
        max = a / 2;
        
    }
//    printing the results
    cout<<min<<" "<<max;
}
