class Solution {
public:
  
  bool dfs(int i,int j,vector<vector<int>> &grid){
     
     if(i>=grid.size()||i<0 || j>=grid[0].size() || j<0){
         return false;   //out of bound return false: corner wale 0 nahi taken karage:
     }

     if(grid[i][j]==1){
          return true;   //base case:
     }

     grid[i][j]=1;   //this will marked as visited:
     int right_call = dfs(i,j+1,grid);
     int left_call = dfs(i,j-1,grid);
     int top_call = dfs(i-1,j,grid);
     int down_call  = dfs(i+1,j,grid);
   
     return right_call && left_call && top_call && down_call;  
  } 

 

    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        
        int cnt = 0;
        for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             if(grid[i][j]==0){
                if(dfs(i,j,grid)==true){
                 cnt++;
                }
             }
         }
        }
        return cnt;
    }
};
