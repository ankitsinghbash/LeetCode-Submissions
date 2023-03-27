class Solution {
public:
   
   
    int solve(int i,int j,vector<vector<int>> &grid,int n,int m,vector<vector<int>> &dp){

        if(i==n-1&&j==m-1){
            return grid[i][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(i>=n||j>=m){
            return 1e9;
        }

     

        int ans =grid[i][j]+min(solve(i+1,j,grid,n,m,dp),solve(i,j+1,grid,n,m,dp));
       return dp[i][j]=ans;
    }

     int minPathSum(vector<vector<int>>& grid) {
         int n=grid.size();
         int m =grid[0].size();
         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
         return solve(0,0,grid,n,m,dp); 
       
    }
};
