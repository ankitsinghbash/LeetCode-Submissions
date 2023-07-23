class Solution {
public:
   vector<pair<int, int>> dir = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};
   double solve(int row,int col,int k,int n,vector<vector<vector<double>>> &dp){
     if(row<0 || col<0 || row>=n || col>=n){
         return 0;
     }

     if(dp[row][col][k]!=-1){
         return dp[row][col][k];
     }

     if(k==0){
         return 1;
     }

    double ans = 0.0;
    for(int i=0;i<dir.size();i++){
        int x = row+dir[i].first;
        int y = col+dir[i].second;
        ans+=solve(x,y,k-1,n,dp)/8.0;
    }
    //  double ans = solve(row-2,col-1,k-1,n,dp)/8.0+solve(row-2,col+1,k-1,n,dp)/8.0+solve(row-1,col+2,k-1,n,dp)/8.0+solve(row+1,col+2,k-1,n,dp)/8.0+solve(row+2,col+1,k-1,n,dp)/8.0+solve(row+2,col-1,k-1,n,dp)/8.0+solve(row+1,col-2,k-1,n,dp)/8.0+solve(row-1,col-2,k-1,n,dp)/8.0;
    return  dp[row][col][k] = ans;
   }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1.0)));
        return solve(row,column,k,n,dp);
    }
};
