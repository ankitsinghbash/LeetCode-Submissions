class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
                                                
        int startrow  = 0;
        int endrow = grid.size()-1;
        int startcol = 0;
        int endcol = grid[0].size()-1;
        
        
        
        
        for(int i=0;i<n;i++){
               bool flag=false;
               for(int j=0;j<m;j++){
                   if(grid[i][j]==1){
                       startrow=i;
                       flag=true;
                       break;
                   }
               }
            if(flag==true) break;
        }
       
        
        for(int i=n-1;i>=0;i--){
             bool flag=false;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    endrow = i;
                    flag=true;
                    break;
                }
            }
             if(flag==true) break;
        }
        
         
        for(int j=0;j<m;j++){
             bool flag=false;
            for(int i=0;i<n;i++){
                if(grid[i][j]==1){
                    startcol = j;
                    flag=true;
                    break;
                }
            }
             if(flag==true) break;
        }
  
        for(int j=m-1;j>=0;j--){
             bool flag=false;
            for(int i=0;i<n;i++){
                if(grid[i][j]==1){
                    endcol = j;
                    flag=true;
                    break;
                }
            }
             if(flag==true) break;
        }
        
     
        if(endrow>=startrow && endcol>=startcol){
            int box = (endrow-startrow+1)*(endcol-startcol+1);
            return box;
        }
        return -1;
    }
};
