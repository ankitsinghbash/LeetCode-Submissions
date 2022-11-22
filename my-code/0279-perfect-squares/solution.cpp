class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<n+1;i++)
        {
            int mini = INT_MAX;
            for(int j=1;j*j<=i;j++)
            {
                int rem = i-j*j;
                mini=min(mini,dp[rem]);
            }
            dp[i]=mini+1;
        }
        return dp[n];
    }
};
