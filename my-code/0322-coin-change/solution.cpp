class Solution {
public:

   
    unsigned int solve(vector<int> &coins,int amount,int idx,vector<vector<int>> &dp){
    
       if(idx<0 || amount<0){
           return 1e9;
       }
   
       if(amount==0){
           return 0;
       }
       if(dp[amount][idx]!=-1){
           return dp[amount][idx];
       }

      unsigned int pick = 1+solve(coins,amount-coins[idx],idx,dp);
       unsigned int notpick = solve(coins,amount,idx-1,dp);
       return dp[amount][idx]=min(notpick,pick);

    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n+1,-1));
        int ans = solve(coins,amount,n-1,dp);
        if(ans==1e9){
            return -1;
        }
        else{
            return ans;
        }
    }
};
