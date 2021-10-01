// To know about the thought process, checkout the editorial on this link : https://discuss.codechef.com/t/swapgame-editorial/94913

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll k, l, m, n, x, y, z;

void solve(int tc = 0)
{
    cin >> n;
    vector<pair<ll,ll>> arr1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i].first;
        arr1[i].second = i;
    }
    
    vector<pair<ll, ll>> arr2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i].first;
        arr2[i].second = i;
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += (arr1[i].first * (arr2[i].second - arr1[i].second));

    cout << ans << endl;
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
