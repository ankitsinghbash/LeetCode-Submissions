class Solution {
public:
    vector<int> ans;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int minrow = 0;
        int maxrow = matrix.size()-1;
        int mincol = 0;
        int maxcol =  matrix[0].size()-1;

        int total = matrix.size()*matrix[0].size();

        int counter = 1;
        while(counter<=total){
 
          for(int j=mincol;j<=maxcol && counter<=total;j++){
              ans.push_back(matrix[minrow][j]);
              counter++;
          }    
          minrow++;
          for(int i=minrow;i<=maxrow && counter<=total;i++){
              ans.push_back(matrix[i][maxcol]);
              counter++;
          }
          maxcol--;
          for(int j=maxcol;j>=mincol && counter<=total;j--){
              ans.push_back(matrix[maxrow][j]);
              counter++;
          }
          maxrow--;
          for(int i = maxrow;i>=minrow && counter<=total;i--){
              ans.push_back(matrix[i][mincol]);
              counter++;
          }
          mincol++;
        }
        return ans;
    }
};
