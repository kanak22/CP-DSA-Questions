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
#define ln cout << "\n";

#define endl "\n"
#define largest 1e18

typedef long long int lli;
typedef vector<int> VI;

long double average(vector<vector<long double>> &s, int i, int j, int n, int m, int u)
{
    long double sum = 0, avg = 0;

    if (i + u < n && j + u < m)
    {
        if (i > 0 && j > 0)
            sum = s[u + i][u + j] - s[i - 1][u + j] - s[u + i][j - 1] + s[i - 1][j - 1];
        else if (i == 0 && j == 0)
            sum = s[u + i][j + u];
        else if (i == 0)
            sum = s[u + i][j + u] - s[u + i][j - 1];
        else if (j == 0)
            sum = s[u + i][j + u] - s[i - 1][j + u];

        avg = (long double)(sum) / ((u + 1) * (u + 1));
    }

    return avg;
}

void solve()
{
    // n = No. of rows
    // m = No. of columns
    // a = 2-D array of integers(Matrix of integers)
    // k = minimum average of integers for a submatrix

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<long double>> a, s;  // s is an 2-D array, to store sum of values of each submatrix
    for (int i = 0; i < n; i++)
    {
        vector<long double> temp_a(m), temp_s(m);
        for (int j = 0; j < m; j++)
        {
            long double num;
            cin >> num;
            temp_a[j] = num;
            if (i == 0 && j == 0)  // taking starting index as (0,0)
                temp_s[j] = num;
            else if (i > 0 && j > 0)
                temp_s[j] = temp_s[j - 1] + s[i - 1][j] + num - s[i - 1][j - 1];
            else if (i == 0)
                temp_s[j] = temp_s[j - 1] + num;
            else if (j == 0)
                temp_s[j] = s[i - 1][j] + num;
        }
        a.push_back(temp_a);
        s.push_back(temp_s);
    }
    /* For example:
     if n=3,m=3 and a = 2 2 3
                        3 4 5
                        4 5 5
     then s = 2  4  7 
              5 11 19 
              9 20 33 
    */
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<s[i][j]<<" ";
    //     }ln
    // }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int v = min(n - i, m - j);
            int u2 = 0;
            // Now using binay search along the diagonal of matrix - s 
            for (int u = v / 2; u >= 0; u /= 2)
            {
                long double avg = 0;
                while (u + u2 < v && average(s, i, j, n, m, u + u2) < k)
                {
                    u2 += u;
                    if (u == 0)
                    {
                        u2++;
                        break;
                    }
                }
                if (u == 0)
                    break;
            }

            if (u2 < v)
            {
                count = count + v - u2;
            }
        }
    }

    cout << count << endl;
}

int main()
{
    fastIO; // Fast input / output
    // No. of cases
    cases(t)
        solve();
}
