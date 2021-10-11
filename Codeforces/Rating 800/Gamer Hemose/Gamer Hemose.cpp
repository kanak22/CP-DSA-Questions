#include <bits/stdc++.h>
 
#define f(a,b,i) for(int i=a;i<b;i++)
#define g(a,b,i) for(int i=b-1;i>=a;i--)
#define int long long
#define pb push_back
#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define mp make_pair
#define CIN(a,x,y) for(int i=x;i<y;i++) cin>>a[i];
#define float double
#define M 1000000007
#define MAX INT_MAX
#define MIN INT_MIN
#define all(a) (a).begin(), (a).end()
//#define N 1010
// #define mp make_pair
using namespace std;
#define fi first
#define sp(n) setprecision(n)
#define se second
#define in insert
#define lb lower_bound
#define ub upper_bound
#define pi pair<int,int>
#define bp(n) __builtin_popcount(n)
#define MAXN 200005
const int N=1e5+10;
const int mod=1000000007;

void solve() {
    int n,h; cin>>n>>h; 
    int a[n]; CIN(a,0,n)

    sort(a,a+n);

    int x = h/(a[n-1]+a[n-2]);
    int y = h%(a[n-1]+a[n-2]);

    // cout<<x<<" "<<y<<endl;
    x*=2;
    if(y>a[n-1]) x+=2;
    else if(y!=0) x++;

    cout<<x<<endl;

}
signed main(){
    FAST_IO
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t; t=1;
    
    cin>>t;
    while(t--){
        //solve();
        solve();
        //if(flag) return 0;
    }
}