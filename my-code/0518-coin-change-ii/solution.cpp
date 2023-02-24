class Solution {
public:

   int solve(int amount,vector<int> &coins,int idx,vector<vector<int>> &dp)
   {
       if(idx<0 || amount<0){
           return 0;
       }

       if(amount==0){
           return 1;
       }
       if(dp[amount][idx]!=-1){
           return dp[amount][idx];
       }

       int pick = solve(amount-coins[idx],coins,idx,dp);
       int notpick = solve(amount,coins,idx-1,dp);

       return dp[amount][idx]=pick+notpick;
   }
 
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n+1,-1));
        return solve(amount,coins,n-1,dp);
    }
};
