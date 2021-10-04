#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string h;
    set<char> s;
    int x,odd=0,even=0;
    cin >> h;
    for(int i=0;i<h.size();i++){
        s.insert(h[i]);
    }
    set<char> ::iterator it;
    it =s.begin();
    for( ; it!=s.end() ; it++){
        x=count(h.begin(),h.end(),*it);
        if(x%2==0){even++;}
        else{odd++;}
    }
    if(odd<2){
        cout << "First";
        return 0;
    }
    else if(odd%2==0){
        cout << "Second";
        return 0;
    }
    else{
        cout << "First";
        return 0;
    }

    return 0;
}
