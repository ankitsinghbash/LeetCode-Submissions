class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size()) return INT_MAX;


        if(i==matrix.size()-1){
            return matrix[i][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

         int mini = INT_MAX;
         for(int k=0;k<matrix[0].size();k++){
                  if(j!=k){
                      int taken = matrix[i][j]+solve(i+1,k,matrix,dp);
                      mini = min(mini,taken);
                  }
         }
        
        return dp[i][j] = mini;

    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        //Do same thing but with the help of recursion:
        int mini = INT_MAX;
        int n = grid.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int j=0;j<n;j++){
                   mini  = min(mini,solve(0,j,grid,dp));
        }
        return mini;
    }
};
