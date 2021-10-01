   // To know about the thought process, checkout the editorial on this link : https://discuss.codechef.com/t/palint-editorial/94376

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;

const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;

ll k, l, m, n, x, y, z;
ll ans = 0;

void solve(int tc = 0)
{
    cin >> n >> x;
    
    int a[n];
    map<ll, ll> mp, xor_map;

    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        
        if((a[i] ^ x) != a[i]) 
        {
            xor_map[a[i] ^ x]++;
            mp[a[i] ^ x]++;
        }
    }

    ans = -1, k = -1, l = 0;
    
    for(auto it : mp)
    {
        if(it.second > k)
	    {
            l = xor_map[it.first];
            k = it.second;
	    }
	    
	    else if(it.second == k && xor_map[it.first] < l)
	        l = xor_map[it.first];
    }

    cout << k << " " << l << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    cin >> tc;
    for (int t = 0; t < tc; t++)
        solve(t);
}   
