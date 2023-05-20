class Solution {
public:
    int dfs(int i,int j,vector<vector<int>> &grid,int prev,vector<vector<int>> &dp){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]<=prev ){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];
        
        int val = grid[i][j];
        int left = dfs(i-1,j+1,grid,val,dp);
        int right = dfs(i,j+1,grid,val,dp);
        int down = dfs(i+1,j+1,grid,val,dp);
        
        return dp[i][j] = max({left,right,down})+1;
    }
    
    
    int maxx = 0;
    int maxMoves(vector<vector<int>>& grid) {
       vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        for(int i=0;i<grid.size();i++){
            int ans = dfs(i,0,grid,INT_MIN,dp);
            maxx = max(maxx,ans);
        }
        return maxx-1;
    }
};
