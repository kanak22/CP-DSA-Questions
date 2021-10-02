#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = (int)1e9 + 7;

// int solve(int *a, int *b, int n, int m, int **memo){
//     if(a[0] < b[0]){
//         return 0;
//     }
//     if(n == 0){
//         return 0;
//     }
//     if(m == 0){
//         return 0;
//     }
//     if(memo[n][m] != -1){
//         return memo[n][m];
//     }
//     int x = solve(a + 1, b + 1, n - 1, m - 1, memo) + 2;
//     int y = solve(a + 1, b, n - 1, m, memo) + 1;
//     int z = solve(a, b + 1, n, m - 1, memo) + 1;

//     memo[n][m] = min(x, min(y, z));
//     return memo[n][m];
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n + 1], b[n + 1];
        for(int i = 1; i <= n; i++){
            cin>>a[i];
        }
        for(int i = 1; i <= n; i++){
            cin>>b[i];
        }

        int ans = INT_MAX;
        int c[2 * n + 1];
        
        for(int i = 1, j = 1; i <= 2 * n; i+=2){
            while(i > b[j]){
                j++;
            }
            c[i] = j - 1;
        }

        for(int i = 1; i <= n; i++){
            ans = min(ans, c[a[i]] + i - 1);
        }

        cout<<ans<<"\n";

        // int **memo = new int*[n + 1];
        // for(int i = 0; i <= n; i++){
        //     memo[i] = new int[n + 1];
        //     for(int j = 0; j <= n; j++){
        //         memo[i][j] = -1;
        //     }
        // }

        // int result = solve(a, b, n, n, memo);

        // cout<<result<<"\n";

    }
    return 0;
}
