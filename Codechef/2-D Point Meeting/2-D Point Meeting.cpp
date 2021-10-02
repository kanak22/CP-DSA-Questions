// To know about the thought process, checkout the editorial on this link : https://discuss.codechef.com/t/pointmee-editorial/94394

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
const ll mod = 1000000007;

ll k, l, m, n, x, y, z;

void solve(int tc = 0)
{
    ll ans=0, temp=0;
    cin >> n;
    
    int a[n], b[n];
    
    // storing the x coordinate 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= 2;
    }
    
    // storing the y coordinate
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] *= 2;
    }
    
    vector<int> x, y;

    // we know that we can move the point only in 8 directions namely 
    // 0°,45°,90°,135°,180°,225°,270°,315°. To minimise, we will take the angles 0°,45°,90°,135°
    
    // so we will find the intersection point by taking the slope of the line 
    // from these angles 0°,45°,90°,135°.

    // The equation will be:
    // 1. x + y = a + b & y = d so the intersection point is (a + b - d, d)
    // 2. x + y = a + b & x = c so the intersection point is (c, a + b - c)
    
    // 3. x + y = a + b & x - y = c - d so the intersection point is ((a + b + c - d) / 2 , (a + b + d - c) / 2)
    // 4. x - y = a - b & x + y = c - d so the intersection point is ((a - b + c + d) / 2 , (b - a + c + d) / 2)
    
    // 5. x - y = a - b & y = d so the intersection point is (a - b + d, d)
    // 6. x - y = a - b & x = c so the intersection point is (c, c - a + b)

    // 6. x = a & y = d so the intersection point is (a, d)
    // 7. x = a & x - y = c - d so the intersection point is (a, a - c + d)
    // 8. x = a & x + y = c + d so the intersection point is (a, c + d - a)
    
    // 9. y = b & x = c so the intersection point is (c, b)
   // 10. y = b & x - y = c - d so the intersection point is (b + c - d, b)
   // 11. y = b & x + y = c + d so the intersection point is (c + d - b, b)
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            
            int a1 = a[i], b1 = b[i], c = a[j], d = b[j];
            x.pb(a1); y.pb(d);
            
            x.pb(c); y.pb(b1 + c - a1);
            x.pb(c); y.pb(b1 - c + a1);
            
            x.pb(a1 + b1 - d); y.pb(d);
            x.pb(a1 - b1 + d); y.pb(d);
            
            x.pb((a1 + b1 + c - d) / 2); y.pb((b1 + a1 - c + d) / 2);
        }
    }

    // we calculate the sum of operations needed for each of the given points to coincide.
    // Minimum of these sums would be our answer.

    for(int i = 0; i < x.size(); i++) {
        temp = 0;
        
        int top = y[i], right = x[i];
        for(int j = 0; j < n; j++) {
            if(right == a[j] && top == b[j]) temp += 0;
            else if(right == a[j] || top == b[j]) temp++;
            else if(abs(right - a[j]) == abs(top - b[j])) temp++;
            else temp += 2; 
        }
        
        if(i == 0) ans = temp;
        else ans = min(temp, ans);
    }

    cout<<ans<<endl;
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
