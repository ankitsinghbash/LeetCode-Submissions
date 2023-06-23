class Solution {
public:
    int solve(vector<int> &prices,int idx,int fee,bool buy,vector<vector<int>> &dp){
       if(idx>=prices.size()){
           return 0;
       }

       if(dp[idx][buy]!=-1) return dp[idx][buy];
 

       int profit = 0;
       if(buy==true){
           int taken = solve(prices,idx+1,fee,false,dp)-prices[idx];
           int nottaken = solve(prices,idx+1,fee,true,dp);
           return dp[idx][buy] = max({profit,taken,nottaken});
       }
       else{
           int sell = prices[idx]+solve(prices,idx+1,fee,true,dp)-fee;
           int notsell = solve(prices,idx+1,fee,false,dp);
           return  dp[idx][buy] = max({profit,sell,notsell});
       }
        return dp[idx][buy] = profit;

    }

    int maxProfit(vector<int>& prices, int fee) {
        int idx=0;
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,idx,fee,true,dp);
    }
};
