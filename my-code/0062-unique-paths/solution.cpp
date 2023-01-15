class Solution {
public:
    //some time tabulation is most easy then use tabulation;

    int solve(int n,int m,int i,int j,vector<vector<int>> &dp){
     
       if(i==n-1&&j==m-1){
           return 1;
       }
       
       
       if(i>=n||j>=m){
           return 0;
       }
  
       if(dp[i][j]!=-1){
          return dp[i][j];
         }

  
       int right = solve(n,m,i,j+1,dp);
       int down = solve(n,m,i+1,j,dp);
     
       return dp[i][j] = right+down;

    }

    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n,m,0,0,dp);
    }
};
/*Tabulation solution:-
    vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=0;i<m+1;i++){
            dp[i][0]=1;
        }
        for(int j=0;j<n+1;j++){
            dp[0][j]=1;
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
*/
