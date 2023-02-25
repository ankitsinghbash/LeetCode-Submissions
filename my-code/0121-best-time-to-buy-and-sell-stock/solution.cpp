class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxx = 0;
        for(int i=0;i<prices.size();i++){
               mini=min(mini,prices[i]);
               if(prices[i]>mini){
                   int val = prices[i]-mini;
                   maxx=max(maxx,val);
               }
        }
        return maxx;
    }
};
