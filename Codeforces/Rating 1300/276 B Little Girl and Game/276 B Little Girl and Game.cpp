#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string h;
    // string h is the main input string
    set<char> s;
    int x,odd=0,even=0;
    cin >> h;
    //here after this loop set 's' will have every unique element of string 'h'
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
    // in above loop i have counted how many times every unique element of set 's' repeats in string 'h'
    //as a palindrome needs only one or zero odd ements , so if there are 1 or 0 odd elements first will win and if odd elenents are more than 1 then it will be decided by whose turn it is
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
