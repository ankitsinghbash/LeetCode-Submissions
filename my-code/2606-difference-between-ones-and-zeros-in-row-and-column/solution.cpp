class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> row_one(grid.size());
        vector<int> col_one(grid[0].size());

        for(int i=0;i<grid.size();i++){
            int one=0;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) one++;
            }
            row_one[i]=one;
        }

        for(int j=0;j<grid[0].size();j++){
            int one=0;
            for(int i=0;i<grid.size();i++){
                if(grid[i][j]==1) one++;
            }
            col_one[j]=one;
        }

        vector<vector<int>> matrix(grid.size(),vector<int>(grid[0].size()));
        int total = grid.size()+grid[0].size();
        for(int i=0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                int val1 = row_one[i];
                int val2 = col_one[j];
                int total_one = val1+val2;
                int total_zero = total-total_one;
                int ans = total_one-total_zero;
                matrix[i][j] = ans;
            }
        }
        return matrix;

    }
};
