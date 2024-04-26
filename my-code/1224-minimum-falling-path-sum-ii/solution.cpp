class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
            int n = grid.size();
            vector<vector<int>> dp(n,vector<int>(n));


            for(int j=0;j<n;j++){
                dp[0][j] = grid[0][j];
            }


            for(int i=1;i<n;i++){
                for(int j=0;j<n;j++){
                       
                       int curr=INT_MAX;
                       for(int k=0;k<n;k++){ //this also show coloum:
                           if(k!=j){   //why k!=j;
                            curr = min(curr,grid[i][j]+dp[i-1][k]);
                           }
                       }

                       dp[i][j] = curr;
                }
            }


            int mini = INT_MAX;
            for(int j=0;j<n;j++){
                 int value = dp[n-1][j];
                 if(value<mini){
                    mini = value;
                 }
            }
            return mini;

    }
};
