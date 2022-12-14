class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<m+1;j++){
            if(j==1){
                dp[0][j]=1;
            }
            else
            {
                dp[0][j]=0;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(obstacleGrid[i-1][j-1]!=1){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n][m];

    }
};
