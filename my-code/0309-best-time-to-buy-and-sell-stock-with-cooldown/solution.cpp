class Solution {
public:
   int solve(vector<int> &prices,bool buy,int idx,vector<vector<int>> &dp){
 
     if(idx>=prices.size()) return 0;

     if(dp[idx][buy]!=-1) return dp[idx][buy];
 

     int profit = 0;
     if(buy==true){
         int taken = solve(prices,false,idx+1,dp)-prices[idx];
         int nottaken = solve(prices,true,idx+1,dp);
         return  dp[idx][buy] = max({profit,taken,nottaken});
     }
     else{
        int sell = prices[idx]+solve(prices,true,idx+2,dp);
        int notsell  = solve(prices,false,idx+1,dp);
        return dp[idx][buy] = max({profit,sell,notsell});
     }
   
      return  dp[idx][buy] = profit;

   }




    int maxProfit(vector<int>& prices) {
        int idx=0;
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,true,idx,dp);
    }
};
