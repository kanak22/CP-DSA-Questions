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

int main(){

   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
    
   ll x,y,p,q;
   cin>>x>>y>>p>>q;

   ll a[x][y];
   vector<vector<bool>> b(x,vector<bool> (y,1));

   a[p][q]=0;    

   b[p][q]=0;

   // Using a bfs call to fill the pattern array

   queue<pair<ll,ll>> r;

   r.push(make_pair(p,q));

   while(!r.empty()){
      pair<ll,ll> s=r.front();
      r.pop();

      ll m=s.first;
      ll n=s.second;

      if(m-1>=0&&n-1>=0&&m-1<x&&n-1<y){
         if(b[m-1][n-1]){
            a[m-1][n-1]=a[m][n]+1;
            b[m-1][n-1]=0;
            r.push(make_pair((m-1),(n-1)));
         }
      }

      if(m-1>=0&&n>=0&&m-1<x&&n<y){
         if(b[m-1][n]){
            a[m-1][n]=a[m][n]+1;
            b[m-1][n]=0;
            r.push(make_pair((m-1),(n)));
         }
      }

      if(m-1>=0&&n+1>=0&&m-1<x&&n+1<y){
         if(b[m-1][n+1]){
            a[m-1][n+1]=a[m][n]+1;
            b[m-1][n+1]=0;
            r.push(make_pair((m-1),(n+1)));
         }
      }

      if(m>=0&&n-1>=0&&m<x&&n-1<y){
         if(b[m][n-1]){
            a[m][n-1]=a[m][n]+1;
            b[m][n-1]=0;
            r.push(make_pair((m),(n-1)));
         }
      }

      if(m>=0&&n+1>=0&&m<x&&n+1<y){
         if(b[m][n+1]){
            a[m][n+1]=a[m][n]+1;
            b[m][n+1]=0;
            r.push(make_pair((m),(n+1)));
         }
      }

      if(m+1>=0&&n-1>=0&&m+1<x&&n-1<y){
         if(b[m+1][n-1]){
            a[m+1][n-1]=a[m][n]+1;
            b[m+1][n-1]=0;
            r.push(make_pair((m+1),(n-1)));
         }
      }

      if(m+1>=0&&n>=0&&m+1<x&&n<y){
         if(b[m+1][n]){
            a[m+1][n]=a[m][n]+1;
            b[m+1][n]=0;
            r.push(make_pair((m+1),(n)));
         }
      }

      if(m+1>=0&&n+1>=0&&m+1<x&&n+1<y){
         if(b[m+1][n+1]){
            a[m+1][n+1]=a[m][n]+1;
            b[m+1][n+1]=0;
            r.push(make_pair((m+1),(n+1)));
         }
      }

   }

   // Printing the array

   for(int i=0;i<x;i++){
      for(int j=0;j<y;j++)
         cout<<a[i][j]<<" ";

      cout<<"\n";
   }

}