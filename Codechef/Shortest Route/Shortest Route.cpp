#include <bits/stdc++.h>
using namespace std;

#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define cases(t) \
    int t;       \
    cin >> t;    \
    while (t--)
#define show(a)             \
    for (auto itr : a)      \
        cout << itr << " "; \
    cout << endl;
#define debugln(x) cerr << #x << " = " << x << endl;
#define debug(x) cerr << #x << " = " << x << "  ";

#define endl "\n"
#define largest 1e18

typedef long long int lli;
typedef long double ld;
typedef vector<int> VI;

void solve()
{ ///
    int n, m;
    cin >> n >> m;
    VI a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<pair<int, int>> t(n); // left and right time for each station
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            t[i].first = 0;
        }
        else
        {
            if (i > 0 && t[i - 1].first != INT_MAX)
            {
                t[i].first += (t[i - 1].first + 1);
            }
            else
                t[i].first = INT_MAX;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 2)
        {
            t[i].second = 0;
        }
        else
        {
            if (i < n - 1 && t[i + 1].second != INT_MAX)
            {
                t[i].second += (t[i + 1].second + 1);
            }
            else
                t[i].second = INT_MAX;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int min_dist = min(t[b[i] - 1].first, t[b[i] - 1].second);
        if (b[i] == 1)
            cout << 0 << " ";
        else if (min_dist == INT_MAX)
            cout << -1 << " ";
        else
            cout << min_dist << " ";
    }

    cout << endl;
}

int main()
{
    fastIO;  // Fast input / output

    cases(t)
        solve();
}