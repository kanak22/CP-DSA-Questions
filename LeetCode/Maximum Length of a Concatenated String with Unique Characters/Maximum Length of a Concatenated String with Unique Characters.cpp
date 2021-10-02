// problem -Maximum Length of a Concatenated String with Unique Characters
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define f(i,a,b) for(ll i=a;i<b;i++)
bool check(string s,string g){
    // function to check if two strings are unique or not
    set<char> st;
    int n=s.length(),m=g.length();
    for(int i=0;i<n;i++){
        st.insert(s[i]);
    }
    for(int i=0;i<m;i++){
        st.insert(g[i]);
    }
    // if all characters are unique
    if(st.size()==(n+m))return true;
    return false;
}
void fun(int i,int &mx,vector<string>& a,string s,int n){
    if(i==n){
        // base case
        int k=s.length();
        mx=max(mx,k);
        return ;
    }
    for(int j=i;j<n;j++){
        if(check(s,a[j])){
            // if s and a[j] can be Concatenated then include this
            fun(j+1,mx,a,s+a[j],n);
        }else{
            int k=s.length();
            mx=max(mx,k);
        }
    }
}
int maxLength(vector<string>& a) {
    int mx=0;
    int n=a.size();
    //recusive function
    fun(0,mx,a,"",n);
    return mx;
}
int main(){
    fast;
    // n is the size of string array
    ll n;
    cin>>n;
    string s;
    vector<string> v;
    for(ll i=0;i<n;i++){
        cin>>s;
        v.push_back(s);
    }
    // function to return max length of a Concatenated String with Unique Characters
    cout<<maxLength(v)<<endl;
}

