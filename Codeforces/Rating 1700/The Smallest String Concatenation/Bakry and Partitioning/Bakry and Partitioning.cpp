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

void dfs(int node, vector<int>& par,vector<vector<int> >& adj,vector<int>& vis,vector<int>& v)
{
    par[node]=v[node-1];
    vis[node]=1;
    for(auto itr: adj[node])
    {
        if(vis[itr]==0)
        {
            vis[itr]=1;
            dfs(itr,par,adj,vis,v);
            par[node]^=par[itr];
        }
    }
    return;
}

void solve() {
    int n,k;
    cin>>n>>k; k-=1;
    vector<int> v(n,0);
    int tmp=0;
    f(0,n,i)
    {
        cin>>v[i];
        tmp^=v[i];
    }
    if(tmp==0 && k>=1)
    {
        f(0,n-1,i)
        {
            int x,y;
            cin>>x>>y;
        }
        cout<<"YES\n"; return;
    }
    vector<int> par(n+1,-1);
    int ans=0;
    vector<vector<int> > adj(n+1);
    f(0,n-1,i)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    par[1]=v[0];
    vector<int> vis(n+1,0);
    vis[1]=1;
    dfs(1,par, adj,vis,v);
    f(2,n+1,i)
    {
        if(par[i]==tmp||par[i]==0)
        {
            ans++;
        }
    }
    if(ans>=2 && k>=2)
    {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
    return;
    
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