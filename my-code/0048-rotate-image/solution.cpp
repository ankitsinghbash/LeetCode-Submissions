class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
           int n = matrix.size();
           int m = matrix[0].size();
           vector<vector<int>> new_matrix(m,vector<int>(n));
           for(int i=0;i<n;i++){
                  for(int j=0;j<m;j++){
                          new_matrix[j][n-i-1] = matrix[i][j];
                  }
           }


           for(int i=0;i<matrix.size();i++){
             for(int j=0;j<matrix[0].size();j++){
                matrix[i][j] = new_matrix[i][j];
             }
           }
    }
};
