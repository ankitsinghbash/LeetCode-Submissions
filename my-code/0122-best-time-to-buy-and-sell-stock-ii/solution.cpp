class Solution {
public:
//let [1,8] -> maxdiff = 8-1=7
//or divided it in number [1,4,8] ->maxdiff=(4-1)+(8-4)=7
//so in division number is greater or equal to (minimum - maximum)
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int max_profit=0;
        for(int i=1;i<n;i++){
             if(prices[i]>prices[i-1]){
                 max_profit+=prices[i]-prices[i-1];
             }
        }
        return max_profit;
    }
};
