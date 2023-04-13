class Solution {
public:
    int diagonalSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int sum=0;
        for(int i=0;i<matrix.size();i++){
             for(int j=0;j<matrix[0].size();j++){
                 if(i==j || i+j==n-1){
                     sum+=matrix[i][j];
                 }
             }
        }
        return sum;
    }
};
