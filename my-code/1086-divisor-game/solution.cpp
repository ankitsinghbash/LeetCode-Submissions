class Solution {
public:
    bool divisorGame(int n) {
        // Tabulation:
        vector<bool> dp(n+1, false);
      
        dp[2] = true;
        for(int i=4;i<n+1;i++) {
            for(int j=1;j<i;j++) {
                if(i%j==0) {  // Alice says i am true means Bob lost:
                    dp[i] = dp[i] | !dp[i-j];
                }
            }
        }
        return dp[n];
    }
};

