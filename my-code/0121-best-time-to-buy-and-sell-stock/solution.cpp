class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minipro = 0;
        int mini = INT_MAX;
        for(int i=0;i<prices.size();i++){
             mini = min(mini,prices[i]);
             int diff = prices[i]-mini;
             minipro = max(minipro,diff);
        }
        return minipro;
    }
};
