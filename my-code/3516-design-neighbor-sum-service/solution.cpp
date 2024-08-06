#include <vector>
#include <unordered_map>
using namespace std;

class neighborSum {
public:
    vector<vector<int>> grids;
    unordered_map<int, pair<int, int>> mp;
    
    neighborSum(vector<vector<int>>& grid) {
        grids = grid;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                mp[grid[i][j]] = {i, j};
            }
        }
    }
    
    int adjacentSum(int value) {
        int adjsum = 0;
       
        
        pair<int, int> P = mp[value];
        int i = P.first;
        int j = P.second;
        
     
        if (i > 0) {
            adjsum += grids[i - 1][j];
        }
        
       
        if (i + 1 < grids.size()) {
            adjsum += grids[i + 1][j];
        }
        

        if (j + 1 < grids[0].size()) {
            adjsum += grids[i][j + 1];
        }
        
       
        if (j > 0) {
            adjsum += grids[i][j - 1];
        }
        
        return adjsum;
    }
    
    int diagonalSum(int value) {
        int adjsum = 0;
    
        
        pair<int, int> P = mp[value];
        int i = P.first;
        int j = P.second;
       
        if (i > 0 && j + 1 < grids[0].size()) {
            adjsum += grids[i - 1][j + 1];
        }
       
        if (i + 1 < grids.size() && j + 1 < grids[0].size()) {
            adjsum += grids[i + 1][j + 1];
        }
       
        if (i + 1 < grids.size() && j > 0) {
            adjsum += grids[i + 1][j - 1];
        }
        
     
        if (i > 0 && j > 0) {
            adjsum += grids[i - 1][j - 1];
        }
        
        return adjsum;
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */

