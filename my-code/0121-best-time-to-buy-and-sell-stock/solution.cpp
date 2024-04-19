class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxx = INT_MIN;

        int curr=INT_MAX;
        for(int i=0;i<prices.size();i++){
               curr = min(curr,prices[i]);
               maxx = max(maxx,prices[i]-curr);
        }


        return maxx;
    }
};
