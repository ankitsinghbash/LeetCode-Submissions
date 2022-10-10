class Solution {
public:
    
   int pathsum(int n, int m, vector<vector<int>> &dp, vector<vector<int>> &grid){
    //dp size and grid size both are same:
    //Bottom Down approach:
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            //case1;
            if(i==n-1&&j==m-1)  //when we are at last grid:
            {
              dp[i][j]=grid[i][j];
            } //case2
            else if(i==n-1)
            {
                 dp[i][j]=dp[i][j+1]+grid[i][j];
            }  //case3
            else if(j==m-1)
            {
               dp[i][j]=dp[i+1][j]+grid[i][j];
            }//case4
            else{
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])+grid[i][j];
            }
        }
    }
   return dp[0][0];
}


    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        int ans = pathsum(n,m,dp,grid);
        return ans;
    }
};
