class Solution {
public:
    
    bool solve(int i,int j,vector<vector<int>> &grid,int cnt){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid.size() || grid[i][j]!=cnt){
            return false;
        }
   
       if(cnt==grid.size()*grid.size()-1){
           return true;
       }     
        
       bool check1 = solve(i-2,j+1,grid,cnt+1);
       bool check2 = solve(i-2,j-1,grid,cnt+1);
       bool check3 =  solve(i+2,j-1,grid,cnt+1);
       bool check4 = solve(i+2,j+1,grid,cnt+1);
        
      bool check5 =   solve(i+1,j-2,grid,cnt+1);
      bool check6 =  solve(i-1,j-2,grid,cnt+1);
      bool check7 = solve(i-1,j+2,grid,cnt+1);
      bool check8 =  solve(i+1,j+2,grid,cnt+1);
        
      return check1 || check2 ||check3 || check4 || check5 || check6 || check7 || check8;
    }
    
    
    
    bool checkValidGrid(vector<vector<int>>& grid){
        int k=0;    //start from 0 to 63 for 8*8 grid:
        return solve(0,0,grid,0);
    }
};
