class Solution {
public:
    //Four type of day happen:
    //1->buy,sell,noop and cooldown:
    //In this type of category with remdem updation always use updated dp algo:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       vector<int> dp(n);
       int buy = INT_MIN;
       int noop = INT_MIN;
       int cooldown = 0;
       int sell = 0;
       for(int i=0;i<n;i++){
           noop = max(noop,buy);
           buy = cooldown - prices[i];
           cooldown = max(cooldown,sell);
           sell = noop + prices[i];
           dp[i]=max(cooldown,sell);
       }
       return dp[n-1];
    }
};
