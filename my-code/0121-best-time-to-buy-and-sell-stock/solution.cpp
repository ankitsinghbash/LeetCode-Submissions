class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxx = INT_MIN;
        int n=prices.size();
        for(int i=0;i<n;i++){
            mini = min(mini,prices[i]);
            maxx = max(maxx,prices[i]-mini);
        }
        return maxx;
    }
};
