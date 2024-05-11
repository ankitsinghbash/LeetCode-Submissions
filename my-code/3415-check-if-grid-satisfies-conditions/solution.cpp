class Solution {
public:
    bool solve(vector<vector<int>> &grid,int n,int m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i+1<n && grid[i][j]!=grid[i+1][j]){
                    return false;
                }
                if(j+1<m && grid[i][j]==grid[i][j+1]){
                    return false;
                }
            }
        }
        return true;
    }
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return solve(grid,n,m);      
    }
};


//Equal to the cell below it, i.e. grid[i][j] == grid[i + 1][j] (if it exists).
//Different from the cell to its right, i.e. grid[i][j] != grid[i][j + 1] (if it exists).
