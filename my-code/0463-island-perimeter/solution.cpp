class Solution {
public:
    int count = 0;
    int solve(vector<vector<int>>& grid,int sr,int sc){
        if(sr>=grid.size() || sc>=grid[0].size() || sr<0 || sc<0 || grid[sr][sc]==0) return 1;
        if(grid[sr][sc]==-1) return 0;
        if(grid[sr][sc]==1) grid[sr][sc]=-1;
        return solve(grid,sr-1,sc)+solve(grid,sr+1,sc)+solve(grid,sr,sc-1)+solve(grid,sr,sc+1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return solve(grid,i,j);
                }
            }
        }
        return 0;
    }
};
