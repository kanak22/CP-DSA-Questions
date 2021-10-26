/***
⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡖⠁⠀⠀⠀⠀⠀⠀⠈⢲⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣼⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣧⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣸⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⡇⠀⢀⣀⣤⣤⣤⣤⣀⡀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣔⢿⡿⠟⠛⠛⠻⢿⡿⣢⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣀⣤⣶⣾⣿⣿⣿⣷⣤⣀⡀⢀⣀⣤⣾⣿⣿⣿⣷⣶⣤⡀⠀⠀⠀⠀
⠀⠀⢠⣾⣿⡿⠿⠿⠿⣿⣿⣿⣿⡿⠏⠻⢿⣿⣿⣿⣿⠿⠿⠿⢿⣿⣷⡀⠀⠀
⠀⢠⡿⠋⠁⠀⠀⢸⣿⡇⠉⠻⣿⠇⠀⠀⠸⣿⡿⠋⢰⣿⡇⠀⠀⠈⠙⢿⡄⠀
⠀⡿⠁⠀⠀⠀⠀⠘⣿⣷⡀⠀⠰⣿⣶⣶⣿⡎⠀⢀⣾⣿⠇⠀⠀⠀⠀⠈⢿⠀
⠀⡇⠀⠀⠀⠀⠀⠀⠹⣿⣷⣄⠀⣿⣿⣿⣿⠀⣠⣾⣿⠏⠀⠀⠀⠀⠀⠀⢸⠀
⠀⠁⠀⠀⠀⠀⠀⠀⠀⠈⠻⢿⢇⣿⣿⣿⣿⡸⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠈⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠐⢤⣀⣀⢀⣀⣠⣴⣿⣿⠿⠋⠙⠿⣿⣿⣦⣄⣀⠀⠀⣀⡠⠂⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠉⠛⠛⠛⠛⠉⠀⠀⠀⠀⠀⠈⠉⠛⠛⠛⠛⠋⠁⠀⠀

   * Author : SUARABH UPADHAYAY
   * E-mail : usaurabh207@gmail.com

   PRACTICE LIKE YOU NEVER WIN, PLAY LIKE YOU NEVER LOOSE 
   
   
***/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ui unsigned int 
#define ldb long double 
#define mod 1000000007
#define mod1 1000003
#define mod2 998244353
#define full LLONG_MAX
#define V vector 
#define VL vector<ll>
#define SS stringstream
#define mkp make_pair
#define lb lower_bound 
#define ub upper_bound 
#define bs binary_search
#define np next_permutation
#define ln length()
#define em empty()
#define DO greater<ll>()
#define DM greater<ll>
#define pb push_back
#define in insert
#define pob pop_back()
#define bg begin()
#define fr front()
#define ed end()
#define bk back()
#define sz size()
#define all(o) ((o).bg,(o).ed)
#define alld(o) ((o).bg,(o).ed,DO)
#define F first
#define S second 
#define stf shrink_to_fit()
#define ig cin.ignore(1,'\n');
#define cg(g) getline(cin,(g))
#define f(g,h,o) for(ll g=h;g<o;g++)
#define f1(g,h,o) for(ll g=h;g>o;g--)
#define f2(g) for(auto E : (g))
#define fm(g) for(auto [X,Y] : (g))
#define AI(g,o) VL g(o); f(i,0,o)cin>>g[i]
#define AO(g,o) f(i,0,o)cout<<g[i]<<" "
#define T ui t; cin>>t; while(t--)
#define T1(g) ui g; cin>>g; while(g--)
#define sp(g) fixed<<setprecision(g)
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma GCC optimize("unroll-loops")

// This Problem is solved by Lazy Propagation approach over segment tree

// A tree has been created by initialising the array named a by 0

VL a,t(4000005,0),lazy(4000005,0);

// Update function

void uu(ll i,ll s,ll e,ll l,ll r,ll v){

   if(s>e)
      return;
    
   if(lazy[i]!=0){
      t[i]+=((e-s+1)*lazy[i]);
      if(s!=e){
         lazy[2*i]+=lazy[i];
         lazy[(2*i)+1]+=lazy[i];
      }

      lazy[i]=0;
   }

   if(s>r||e<l)
      return;
   
   if(l<=s&&r>=e){
      t[i]+=((e-s+1)*v);

      if(s!=e){
         lazy[2*i]+=v;
         lazy[(2*i)+1]+=v;
      }
      
      return ;
   }

   ll m=(s+e)/2;
   uu(2*i,s,m,l,r,v);
   uu((2*i)+1,m+1,e,l,r,v);

   t[i]=t[2*i]+t[(2*i)+1];
}

// Query Function

void qu(ll i,ll s,ll e){
   if(s>e)
   return;

   if(lazy[i]!=0){
      t[i]+=((e-s+1)*lazy[i]);
      if(s!=e){
         lazy[2*i]+=lazy[i];
         lazy[(2*i)+1]+=lazy[i];
      }

      lazy[i]=0;
   }

   if(s==e){
      a.pb(t[i]);
      return ;
   }

   ll m=(s+e)/2;
   qu(2*i,s,m);
   qu((2*i)+1,m+1,e);

   t[i]=t[2*i]+t[(2*i)+1];
}

int main(){

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   // Taking inputs 
    
   ll n,m;
   cin>>n>>m;

   ll x,y;

   while(m--){
      cin>>x>>y;

      uu(1,1,n,x,y,1);
   }

   qu(1,1,n);

   sort all(a);

   // Taking Queries one by one

   T{
      cin>>x;
      // Taking lowerbound in the tree
      y=lb(a.bg,a.ed,x)-a.bg;
      cout<<n-y<<"\n";
   }

}