class Solution { 
    public:
     bool checkXMatrix(vector<vector<int>>& grid) 
     { 
         bool flag=true; 
         int row=grid.size(); 
         int col=grid[0].size(); 
         for(int i=0;i<row;i++)
         {
              for(int j=0;j<col;j++)
              { 
                  if(i==j && grid[i][j]==0)
                   return false; 
                  else if(i+j==row-1 && i!=j) 
                  continue; 
                  else if(i!=j && grid[i][j]!=0) 
                  return false; 
                 } 
        }
        
     int n=0; 
     int m=col-1;
     while(n<row && m>=0)
     { 
         if(grid[n][m]==0)
         {
              flag=false; 
              break;
         }
          n++; 
          m--; 
     }
      return true && flag;
 } 
 };
