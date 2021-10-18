#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = (int)1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {

        // Input
        int n;
        cin >> n;
        int a[n + 1], b[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }

        // Variable to store answer to the problem
        int ans = INT_MAX;

        // Using array indexing to store results for every odd number
        int c[2 * n + 1];

        for (int i = 1, j = 1; i <= 2 * n; i += 2)
        {
            // if odd number i is greater than number at b[j] then we have to check for b[++j]
            while (i > b[j])
            {
                j++;
            }
            // When i becomes smaller or equal to b[j] then we can assign index j - 1 to c[i] which represents that i is smaller than the value at b[j]
            c[i] = j - 1;
        }

        // Checking for smallest possible value
        for (int i = 1; i <= n; i++)
        {
            ans = min(ans, c[a[i]] + i - 1);
        }

        // Output
        cout << ans << "\n";
    }
    return 0;
}
