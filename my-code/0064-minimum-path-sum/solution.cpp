class Solution {
public:
    int minPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        dp[0][0]=matrix[0][0];
        int prev=matrix[0][0];
        for(int i=1;i<n;i++){
            prev = matrix[i][0]+prev;
            dp[i][0]=prev;
        }

        int oldprev = matrix[0][0];
        for(int j=1;j<m;j++){
            oldprev = matrix[0][j]+oldprev;
            dp[0][j]=oldprev;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int val = min(dp[i-1][j],dp[i][j-1]);
                dp[i][j] = matrix[i][j]+val;
            }
        }

        return dp[n-1][m-1];

    }
};


