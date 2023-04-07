class Solution {
public:

     //we use bound as a INT_MAX;
    int dfs(int i,int j,vector<vector<int>> &grid){
       if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()){
           return INT_MAX;
       }

       if(grid[i][j]==0) return 0;

       grid[i][j]=0;

       int left_call = dfs(i+1,j,grid);
       int right_call =dfs(i-1,j,grid);
       int top_call = dfs(i,j+1,grid);
       int down_call = dfs(i,j-1,grid);

       if(left_call == INT_MAX || right_call == INT_MAX || top_call==INT_MAX || down_call == INT_MAX){
            return INT_MAX;
       }
       else{
       return left_call+right_call+top_call+down_call+1;
       }
    }
 
    int numEnclaves(vector<vector<int>>& grid){
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                 if(grid[i][j]==1){
                     int value = dfs(i,j,grid);
                     if(value!=INT_MAX){
                         ans+=value;
                     }
                 }
            }
        }
        return ans;
    }
};
