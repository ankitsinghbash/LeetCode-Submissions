class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        //for more help https://www.youtube.com/watch?v=YtOzNodX_aw
        int n=arr.size();
        vector<int> dp(n+1);
        dp[0]=0;
        for(int i=1;i<n+1;i++)
        {
            int maxx=INT_MIN;
            int best = INT_MIN;
            for(int j=1;j<=k&&i-j>=0;j++)
            {
                  maxx=max(maxx,arr[i-j]);
                  best=max(best,dp[i-j]+maxx*j);
            }
            dp[i]=best;
        }
        return dp[n];

    }
};
