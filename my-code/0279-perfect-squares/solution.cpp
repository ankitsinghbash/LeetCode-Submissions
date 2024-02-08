class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<n+1;i++){
             for(int val=1;val*val<=i;val++){
                 dp[i] = min(dp[i],dp[i-val*val]+1);
             }
        }
        return dp[n];
    }
};
