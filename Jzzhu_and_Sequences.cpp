#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod =1000000007;
int main()
{

    ll x,y,n;
    cin>>x>>y>>n;
    vector<ll>pattern;
    pattern.push_back(x);
    pattern.push_back(y);
    pattern.push_back(y-x);
    pattern.push_back(-x);
    pattern.push_back(-y);
    pattern.push_back(x-y);

    if(pattern[((n-1)%6)]%mod>=0)
        cout<<(pattern[(n-1)%6])%mod;
    else
        cout<<mod+(pattern[(n-1)%6])%mod;

    return 0;
}
