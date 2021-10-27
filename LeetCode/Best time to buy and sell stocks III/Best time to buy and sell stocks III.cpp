/*
Question Link:
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
/*
Input: k = 2, prices = [2,4,1]
Output: 2
*/

class Solution {
public:
    int dp[100001][2][3];
    // k is the max transactions we can perform which is 2.
    int solve(int i,int own,int k,vector<int>& prices)
    {
        // if i becomes greater than prices array length then there are no more stocks left . hence we return.
        if(i>=prices.size())
        {
            return 0;
        }
        // if the number of transactions performed become greater than k then also we return since you can perform max k transactions.
        if(k<=0)
        {
            return 0;
        }
        // memoize ... check if the situation already exist then we just take that value.
        if(dp[i][own][k]!=-1)
        {
            return dp[i][own][k];
        }
        // if you own a stock at that paticular day then you two options either to sell it or dont sell that stock.
        // we call solve function for both the options.
        if(own)
        {
            // if we decide to sell the stock then we add the price of stock at that day
            // then we go to next day that is increment i , and make variable own to 0 , and reduce the number of transaction available to us by 1
            int opt1=prices[i]+solve(i+1,0,k-1,prices);

             // if we do not sell the stock then 
            //  we go to next day that is increment i , do not change the own variable cause we still own the stock , and pass k unchanged
            int opt2=solve(i+1,1,k,prices);
            
            // we store the max of the two in the dp array cause we have to maximize the profit
            dp[i][1][k]=max(opt1,opt2);
            // hence we return this value.
            return dp[i][1][k];
        }
        // if you do not own a stock at that paticular day then you two options either to buy the stock on that day or dont buy.
        // we call solve function for both the options.
        else
        {
            // if we decide to buy the stock then we subtract the price of stock at that day
            // then we go to next day that is increment i , and make variable own to 1 , and pass k unchanged
            int opt1=-(prices[i])+solve(i+1,1,k,prices);
            
             // if we do not buy the stock then 
            //  we go to next day that is increment i , do not change the own variable cause we still dont own the stock , and pass k unchanged
            int opt2=solve(i+1,0,k,prices);

            // we store the max of the two in the dp array cause we have to maximize the profit
            dp[i][0][k]=max(opt1,opt2);
            // hence we return this value.
            return dp[i][0][k];
        }
    }
    int maxProfit(vector<int>& prices) {
        // set the dp array to -1 initially
        memset(dp,-1,sizeof(dp));

        // call the solve function 
        // pass 0 in i cause we start with the 0th element in the prices array
        // then we pass 0 in own variable cause we do not own a stock at the starting
        // we pass 2 as k where k denotes the max transactions I can perform
       return solve(0,0,2,prices); 
    }
};