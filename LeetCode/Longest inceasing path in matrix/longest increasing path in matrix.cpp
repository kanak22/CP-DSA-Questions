/*
Link of the question:
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
*/
class Solution {
public:
    // initialize a dp array for memoization
    int dp[201][201];

    // solve function 
    int solve(vector<vector<int>>& matrix,int n,int m,int i,int j)
    {
        // if i greater than number of rows or j greater than numbe of columns then return -1
        if(i>=n || j>=m || j<0 || i<0)
        {
            return -1;
        }
        // if we already visited that cell then return the value in the dp matrix for that cell
        //memoize
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        // initialize the l,r,d,u variables to 0
        int l=0,r=0,u=0,d=0;
        // check if i+1<n and if matrix[i+1][j] < matrix[i][j] then call the solve function for the same.
        if(i+1<n && matrix[i+1][j]<matrix[i][j])
        {
            l=1+solve(matrix,n,m,i+1,j);
        }
        //similarly for i-1
        if(i-1>=0 && matrix[i-1][j]<matrix[i][j])
        {
            r=1+solve(matrix,n,m,i-1,j);
        }
         //similarly for j+1
        if(j+1<m && matrix[i][j+1]<matrix[i][j])
        {
            d=1+solve(matrix,n,m,i,j+1);
        }
         //similarly for j-1
        if(j-1>=0 && matrix[i][j-1]<matrix[i][j])
        {
            u=1+solve(matrix,n,m,i,j-1);
        }
        // now store the max in dp array
        dp[i][j]=max(max(l,r),max(d,u));
        if(dp[i][j]==0)
        {
            dp[i][j]++;
        }
        // return dp[i][j]
        return dp[i][j];
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // initialize dp to -1
        memset(dp,-1,sizeof(dp));
        int n=matrix.size(),m=matrix[0].size();
        int m1=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // call solve for each cell
                 int p=solve(matrix,n,m,i,j);
                 m1=max(p,m1);
            }
        }
        return m1;
       
    }
};