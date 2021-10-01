class Solution
{
    public:
    int knapsack_recursive(int W,int wt[],int val[],int dp[][1001],int n){
        // base case if capacity of knapsack becomes 0
        // or size of weight array becomes 0 then we return 0 
        if(n==0||W==0) return 0;
        int ans;
        // If the ans is already computes then return it from dp
        if(dp[n][W]>0) return dp[n][W];
  
        if(wt[n-1]<=W){
            // if our capacity in knapsack is greater than the current weight 
            // then we will have two choices
            // first is to include that weight and second one is to exclude that
            // We will return the max value from those two choices 
            ans = max(val[n-1]+knapsack_recursive(W-wt[n-1],wt,val,dp,n-1),knapsack_recursive(W,wt,val,dp,n-1));
        }
        else{
            // if the current weight is more than the capacity in knapsack then
            // we will have only one choice that is to exclude that weight
            ans = knapsack_recursive(W,wt,val,dp,n-1);
        }
        dp[n][W] = ans;
        return ans;
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       // Making dp of size 1001 as our constraint is <=1000
        int dp[n+1][1001]={};
        return knapsack_recursive(W,wt,val,dp,n);
    }
};