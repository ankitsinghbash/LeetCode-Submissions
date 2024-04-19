class Solution {
public:
    void bfs(int i,int j,vector<vector<char>> &grid){
        
          vector<int> dir_x = {-1,1,0,0};
          vector<int> dir_y = {0,0,-1,1};

          queue<pair<int,int>> qu;
          qu.push({i,j});
          grid[i][j]='0';
          while(!qu.empty()){
              int size = qu.size();
              while(size--){
                pair<int,int> P = qu.front();
                qu.pop();
                int curr_x = P.first;
                int curr_y = P.second;
                 
                //Go in all four direction:
                for(int k=0;k<4;k++){
                    int new_x = curr_x+dir_x[k];
                    int new_y = curr_y+dir_y[k];

                    
                
                    if(new_x<0 || new_x>=grid.size() || new_y<0 || new_y>=grid[0].size() || grid[new_x][new_y]=='0'){
                        continue;
                    }

                    if(grid[new_x][new_y]=='1'){
                        grid[new_x][new_y]='0';
                        qu.push({new_x,new_y});
                    }

                } 
             

              }
          }
    

    }

    int numIslands(vector<vector<char>>& grid) {
        //using bfs:
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    bfs(i,j,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
