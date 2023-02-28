class Solution {
public:
 
   int solve(int n,int val,vector<int> &dp){
 
    if(n==0){
        return 0;
    }

    if(val*val>n){   //but more approcriate is if(val*val>n)
        return 1e9;
    }
    
     if(dp[n]!=-1){
         return dp[n];
     }
   
     int pick = 1+solve(n-val*val,val,dp);
     int notpick = solve(n,val+1,dp);

     return dp[n]=min(pick,notpick);

   }
   
 
    int numSquares(int n) {
      vector<int> dp(n+1,-1);
        return solve(n,1,dp);
    }
};
