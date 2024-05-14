class Solution {
public:
    int dfs(int i,int j,vector<vector<bool>> &visited,vector<vector<int>> &grid){
            if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || visited[i][j]==true || grid[i][j]==0){
                return 0;
            }

            
            visited[i][j]=true;
            int cnt=0;
            cnt+=grid[i][j]+max({dfs(i+1,j,visited,grid),dfs(i-1,j,visited,grid),dfs(i,j+1,visited,grid),dfs(i,j-1,visited,grid)});
            visited[i][j]=false;

            return cnt;

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        //every time apply dfs:
        int n = grid.size();
        int m = grid[0].size();
        int maxx = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                  if(grid[i][j]!=0){
                      vector<vector<bool>> visited(n,vector<bool>(m));
                       int value = dfs(i,j,visited,grid);
                       maxx = max(maxx,value);
                  }
            }
        }
        return maxx;
    }
};
