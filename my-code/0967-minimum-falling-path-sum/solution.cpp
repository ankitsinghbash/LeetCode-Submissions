class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size()));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i==0){
                    dp[i][j]=matrix[i][j];
                }
                else if(i!=0 && j==0){
                    dp[i][j] = matrix[i][j]+min({dp[i-1][j],dp[i-1][j+1]});
                }
                else if(i!=0 && j==matrix[0].size()-1){
                       dp[i][j] = matrix[i][j]+min({dp[i-1][j],dp[i-1][j-1]});
                }
                else{
                    dp[i][j] = matrix[i][j]+min({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]});
                }
            }
        }

        int mini = INT_MAX;
        int n = matrix.size()-1;
        for(int j=0;j<matrix[0].size();j++){
            int val = dp[n][j];
            mini = min(mini,val);
        }
        return mini;
    }
};
