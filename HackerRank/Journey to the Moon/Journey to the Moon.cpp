/*
Link to the problem: https://www.hackerrank.com/challenges/journey-to-the-moon/problem

Problem statement: A list of pairs of astronaut ID's belonging to same country is given.
Determine how many pairs of astronauts from different countries we can choose from.

Approach: We will use DFS to find number of astronauts belonging to different countries by finding
size of each cycle. We will store the length of different cycles in a vector and then traverse the
vector to find the required solution.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back


vector<ll>g[2*100001];
ll vis[2*100001]; // Array vis tells us whether a given country is visited or not
vector<ll>v;
ll f=0;
void dfs(ll s)
{
    vis[s]=1;
    f++;
    for(ll i=0;i<g[s].size();i++)
    {
        if(!vis[g[s][i]])
        {
            dfs(g[s][i]);
        }
    }
}

int main()
{
    ll n,i,j,p;
    cin>>n>>p;
    ll x,y;
    while(p--)
    {
        cin>>x>>y;
        // x and y belong to same country
        g[x].pb(y);
        g[y].pb(x);
    }
    ll z=0;
    memset(vis,0,sizeof(vis));
    for(i=0;i<n;i++)
    {
        if(!vis[i])
        {
            f=0;
            dfs(i);
            v.pb(f);
            z+=f;
        }
    }
    ll ans=0;
    for(i=0;i<v.size();i++)
    {
        //cout<<v[i]<<" ";
        z=z-v[i];
        ans=ans+z*v[i];
        // The members of country i can form pairs with the remaining astronauts i.e. z-v[i]
    }
    cout<<ans;
}

/*
Space Complexity: O(n)
Time Complexity: O(n) // we visit all the countries during DFS
Algorithm Used: Cycle length using DFS
*/
