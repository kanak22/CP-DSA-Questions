#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;          //number of game rounds
    cin>>n;
    int s1=0,s2=0;          //cumulative sum of player 1 & 2 r
    int winner,lead=0;      //winner name ,lead
    int diff=0;
    for (int i=0;i<n;i++){
        int p1,p2;          //points of each round
        cin>>p1>>p2;
      s1+=p1;               //add each round points in s1
      s2+=p2;               //add each round points in s2
    if (s1>s2){     
        diff=s1-s2;
        if(diff>lead){
            lead=diff;
            winner=1;
        }
    }else {
        diff=s2-s1;
        if(diff>lead){
            lead=diff;
            winner=2;
        }
    }
    }
    cout<<winner<<" "<<lead;            //display winner with lead
    return 0;
}
