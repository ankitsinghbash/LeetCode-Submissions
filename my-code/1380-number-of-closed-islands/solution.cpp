class Solution {
public:
   vector<int> dir_x = {-1,1,0,0};    
   vector<int> dir_y = {0,0,-1,1};
      
    //    i-1,j
    //   i+1,j
     
    //   j-1,i
    //   j+1,i

    bool dfs(int i,int j,vector<vector<int>> &grid){
            if(i<0 || j< 0 || i>=grid.size() || j>=grid[0].size()) return false;

           

             if(grid[i][j]==1 || grid[i][j]==2) return true;

            
            
                 grid[i][j]=2; //when i found 0;
                bool down = dfs(i+1,j,grid);
                bool right = dfs(i,j+1,grid);
                bool up = dfs(i-1,j,grid);
                bool left = dfs(i,j-1,grid);
                return down && right && up && left;
             

    }





    int closedIsland(vector<vector<int>>& grid) {
        //algo:
        /*
            apply dfs on 0:
            return when in four direction has 1 and 2, return true:
            else return false;

        */
 
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                   if(grid[i][j]==0){
                       if(dfs(i,j,grid)==true){
                         cnt++;
                       }
                   }
            }
        }


         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            cout<<grid[i][j]<<",";
            }
            cout<<endl;
        }
        return cnt;
    }
};
