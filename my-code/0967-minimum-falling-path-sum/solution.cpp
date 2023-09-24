class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //classical dp problem:
        //bottom up approach:
 
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));

        for(int j=0;j<col;j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i=1;i<row;i++){
            for(int j=0;j<col;j++){
                if(j==0){
                    dp[i][j] = matrix[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
                }
                else if(j==col-1){
                    dp[i][j] = matrix[i][j]+min(dp[i-1][j-1],dp[i-1][j]);
                }
                else{
                    dp[i][j]=matrix[i][j]+min({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]});
                }
            }
        }


        int mini = INT_MAX;
        for(int j=0;j<col;j++){
            mini = min(mini,dp[row-1][j]);
        }
        return mini;

    }
};
