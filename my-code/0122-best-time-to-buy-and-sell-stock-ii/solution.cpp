class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n = price.size();
        int ans = 0;
        for(int i=1;i<n;i++){
            if(price[i]>price[i-1]){
                ans+=price[i]-price[i-1];
            }
        }
        return ans;
    }
};
