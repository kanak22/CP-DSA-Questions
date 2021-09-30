#include <bits/stdc++.h>
using namespace std;

void solve(int tc = 0)
{
    int n, W;
    cin >> n >> W;

    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    int arr[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                arr[i][j] = 0;

            else if (j >= wt[i - 1])
                arr[i][j] = max(val[i - 1] + arr[i - 1][j - wt[i - 1]], arr[i - 1][j]);

            else if (j < wt[i - 1])
                arr[i][j] = arr[i - 1][j];
        }
    }

    cout << arr[n][W] << endl;
}

int main()
{
    int tc = 1;
    cin >> tc;
    for (int t = 0; t < tc; t++)
        solve(t);
}