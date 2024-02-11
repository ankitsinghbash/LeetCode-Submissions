class Solution {
public:
   int solve(int row,int y1,int y2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
           if(row<0 || row>=grid.size() || y1<0 || y1>=grid[0].size() || y2<0 || y2>=grid[0].size()){
               return INT_MIN;
           }
           
           if(dp[row][y1][y2]!=-1) return dp[row][y1][y2];
            
           if(row==grid.size()-1){
               if(y1==y2){
                   return grid[row][y1];
               }
               return grid[row][y1]+grid[row][y2];
           }


           int cherry=0;
           cherry+=grid[row][y1];
           if(y1!=y2){
               cherry+=grid[row][y2];
           }

           int ans = 0;
           for(int i=-1;i<=1;i++){
               for(int j=-1;j<=1;j++){
                   int new_y1 = y1+i;
                   int new_y2 = y2+j;
                   int new_row = row+1;
                     ans = max(ans,cherry+solve(new_row,new_y1,new_y2,grid,dp));
               }
           }
    
           return dp[row][y1][y2] = ans;

   }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        return solve(0,0,m-1,grid,dp);
    }
};
