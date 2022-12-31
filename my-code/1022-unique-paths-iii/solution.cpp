class Solution {
public:

   int dfs(int x,int y,int zero,vector<vector<int>> &grid)
   {
       //base case of the position we never visited:
       if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||grid[x][y]==-1){
           return 0;
       }
       //a)Happen when i reah to final postion as 2;
       //if(zero==-1) mean i jump to all zero hence i conver all the necessary value 0 so my counter is 1 here:
      if(grid[x][y]==2){
          if(zero==-1){
              return 1;   //1 means one path:
          }
          else
          {
              return 0;   //0 mean zero path:
          }
      }


      //Now as we know the base case of visited is already assign in base case as:
      //grid[x][y]==-1 return 0; so use this as a already visited node:
       
        zero--;
        grid[x][y]=-1;  //mean i visited the current box:
        int total = dfs(x-1,y,zero,grid)+dfs(x,y-1,zero,grid)+dfs(x+1,y,zero,grid)+dfs(x,y+1,zero,grid);
        grid[x][y]=0;   //now again you visisted the box in backtracking:
        zero++;
    
     return total;
   }


    int uniquePathsIII(vector<vector<int>>& grid) {
        //count the zero 
        //zero approach solution:
        int zero=0;
        int x,y;  //coodinate of (1) start point:
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0) zero++;
                else if(grid[i][j]==1){
                    x=i;
                    y=j;
                }
            }
        }
        int totalcounter=dfs(x,y,zero,grid);
        return totalcounter;
    }

};
