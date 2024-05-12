class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
           
            int n = grid.size();
            int m = grid[0].size(); //n==m it square matrix;
             vector<vector<int>> result(n-2,vector<int>(m-2));
            for(int i=0;i<n-2;i++){
                for(int j=0;j<m-2;j++){
                    int value = grid[i][j];
                    int maxx = INT_MIN;
                    for(int l=i;l<i+3;l++){
                        for(int k=j;k<j+3;k++){
                            int value = grid[l][k];
                            maxx = max(maxx,value);
                        }
                    }
                    result[i][j]=maxx;
                }
            }
            return result;

    }
};
