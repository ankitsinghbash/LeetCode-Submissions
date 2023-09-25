int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
class Solution {
public:
    double solve(int i,int j,int water,vector<vector<double>> &dp){
       if(i<0 || j>i || j<0){
           return 0.00;
       }

       if(i==0 && j==0){
           return  water;
       }

       if(dp[i][j]!=-1){
           return dp[i][j];
       }
  
       double left_up = (solve(i-1,j-1,water,dp)-1)/2.0;
       double right_up = (solve(i-1,j,water,dp)-1)/2.0;

       if(left_up<0){
           left_up=0.0;
       }
       if(right_up<0){
           right_up=0.0;
       }
    //    if(left_up+right_up>=1){
    //        return 1.0;
    //    }

       return dp[i][j] = left_up+right_up;
    }


    double champagneTower(int poured, int query_row, int query_glass) {
         int row = query_row;
         int col = query_glass;
         //memset(dp,-1,sizeof(dp));
         vector<vector<double>> dp(101,vector<double>(101,-1));
         return min(1.0,solve(row,col,poured,dp));
    }
};
