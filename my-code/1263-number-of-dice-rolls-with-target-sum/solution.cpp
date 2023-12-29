class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0]=1;  
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                int ans=0;
                for (int x=1;x<=k;x++) {
                    if(x<=j){
                       ans = (ans%mod+dp[i-1][j-x]%mod)%mod; 
                    }
                }
                dp[i][j]=ans%mod;
            }
        }
        
        return dp[n][target];
    }
};

