// Problem Link: https://codeforces.com/contest/121/problem/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll i=a;i<b;i++)
int main() {
	ll l,r;
	cin>>l>>r;
    /* Creating a vector storing all possible combinations of 4 and 7.
       '0' will represent '4' and '1' will represent '7'. For example '010' will represent '474'. */ 
	vector<ll> v;
	f(j,1,11){
	    ll len=pow(2,j);
	    f(k,0,len){
	        string s=bitset<10>(k).to_string();
	        for(ll p=s.length()-1;p>=10-j;p--){
	            if(s[p]=='0')s[p]='4';
	            else s[p]='7';
	        }
	        ll g=stoll(s);
	        v.push_back(g);
	    }
	}
	ll s=0;
	ll i=l;
	while(i<=r){
	    ll ans=(lower_bound(v.begin(),v.end(),i)-v.begin());
        // For numbers between i and k result would be v[ans] only.
	    ll k=min(v[ans],r);
	    s+=(k-i+1)*v[ans];
	    i=v[ans]+1;
	}
	cout<<s<<endl;
}
