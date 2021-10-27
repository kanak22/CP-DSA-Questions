// PROBLEM STATEMENT
Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.
Example 1:
Input:
N = 16
A[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
Output: 6
Explanation:Longest increasing subsequence
0 2 6 9 13 15, which has length 6


// CODE 
#include<bits/stdc++>
using namespace std;

class Solution
{
    public:
    //FUNCTION TO FIND THE LENGTH OF LONGEST INCREASING SUBSEQUENCE 
    int LIS(int n, vector<int>&a)
    {
      vector<int>b(n);
      b=a;
      sort(b.begin(),b.end());
      
      vector<vector<int>v(n+1,vector<int>(n+1));
      for(int i=0;i<=n;++i)
      for(int j=0;j<=n;++j)
      {
       if(i==0||j==0)
         v[i][j]=0;
       else if(a[i-1]==b[j-1])
         v[i][j]= 1 + v[i-1][j-1];
       else 
         v[i][j]=max(v[i-1][j] , v[i][j-1] );
      }
      
      return v[n][n];
    }
};

int main()
{
  //TOTAL TESTCASES 
  int t;
  cin>>t;
  while(t--)
  {
   // SIZE OF ARRAY
   int n;
   cin>>n;
   vector<int>a(n);
   
   //INSERTING ELEMENTS TO THE ARRAY
   for(int i=0;i<n;i++)
   cin>>a[i];
   
   Solution ob;
   
   //CALLING METHOD LIS()
   cout<<ob.LIS(n,a)<<endl;
   }
  return 0;
 }
  
