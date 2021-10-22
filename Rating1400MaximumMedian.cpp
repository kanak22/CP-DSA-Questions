// https://codeforces.com/contest/1201/problem/C
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
ll x;
vector < ll > a;
bool check(ll x)
{
    ll moves=0;
    for (int i=n/2; i<n; i++)
    {
        if (x-a[i]>0) moves+=x-a[i];
        if (moves>k) return false;
    }
    if (moves<=k) return true;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for (int i=1; i<=n; i++)
    {
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    ll small=1;
    ll big=2000000000;
    while (small!=big)
    {
        ll mid=(small+big+1)/2;
        if (check(mid))
        {
            small=mid;
        }
        else{
            big=mid-1;
        }
    }
    cout<<small;
}
