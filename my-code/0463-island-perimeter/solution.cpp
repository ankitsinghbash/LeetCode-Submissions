class Solution {
public:

int bfs(int i, int j, vector<vector<int>>& grid) {
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    queue<pair<int,int>> qu;
    grid[i][j] = -1;
    qu.push({i, j});
    int ans = 0;
    while (!qu.empty()) {
        int size = qu.size();
        while (size--) {
            pair<int,int> P = qu.front();
            qu.pop();
            int curr_x = P.first;
            int curr_y = P.second;
            for (int k = 0; k < 4; k++) {
                int new_i = curr_x + dx[k];
                int new_j = curr_y + dy[k];
                int m = grid.size();
                int n = grid[0].size();
                if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || grid[new_i][new_j] == 0) {
                    ans++;
                } else if (grid[new_i][new_j] == 1) { 
                    grid[new_i][new_j] = -1; 
                    qu.push({new_i, new_j});
                }
            }
        }
    }
    return ans;
}



    int islandPerimeter(vector<vector<int>>& grid) {
        //using bfs:
          int cnt=0;
          for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                   if(grid[i][j]==1){
                      cnt+=bfs(i,j,grid);
                      break;
                   }
            }
          }
          return cnt;
    }
};
