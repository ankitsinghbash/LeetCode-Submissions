class Solution {
public:
   
   const int mod = 1e9+7;
   int solve(int i,int j,int m,int n,int maxmove,vector<vector<vector<int>>> &dp){
         
           if(maxmove<0) return 0;

           if(i<0 || j<0 || i>=m || j>=n){
                if(maxmove>=0){
                    return 1;
                }
                return 0;
           }
           
           if(dp[i][j][maxmove]!=-1) return dp[i][j][maxmove];

           int total=0;
           total=(total%mod+solve(i+1,j,m,n,maxmove-1,dp)%mod)%mod;
           total=(total%mod+solve(i-1,j,m,n,maxmove-1,dp)%mod)%mod;
           total=(total%mod+solve(i,j+1,m,n,maxmove-1,dp)%mod)%mod;
           total=(total%mod+solve(i,j-1,m,n,maxmove-1,dp)%mod)%mod;

           dp[i][j][maxmove] =  total%mod;
           return dp[i][j][maxmove];
   }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(51,vector<vector<int>>(51,vector<int>(51,-1)));
        return solve(startRow,startColumn,m,n,maxMove,dp);
    }
};
