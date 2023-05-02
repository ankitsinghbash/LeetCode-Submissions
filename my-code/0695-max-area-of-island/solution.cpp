class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &visited){
     queue<pair<int,int>> qu; //x and y: direction:
     vector<int> dir_x = {0,0,1,-1};
     vector<int> dir_y = {1,-1,0,0};

     int cnt=0;
     qu.push({i,j});
     visited[i][j]=true;
     while(!qu.empty()){
        auto my_pair = qu.front();
        qu.pop();
        cnt++;
        for(int d=0;d<4;d++){
          int dr = my_pair.first + dir_x[d];
          int dc = my_pair.second + dir_y[d];
          if(dr<0 || dc<0 || dr>=grid.size() || dc>=grid[0].size() || grid[dr][dc]==0 || visited[dr][dc]==true){
              continue;
          }
          visited[dr][dc]=true;
          qu.push({dr,dc});
        }
     }
     return cnt;
}  



    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //Queue method:
        int maxx = 0;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && visited[i][j]==false ){
                    maxx=max(maxx,solve(i,j,grid,visited));
                }
            }
        }
        return maxx;
    }
};
