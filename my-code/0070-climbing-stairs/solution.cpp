class Solution {
public:

    int solve(int n,int idx,int dp[]){
  
       if(idx==n){
           return 1;
       }

       if(idx>n){
           return 0;
       }

       if(dp[idx]!=-1){
           return dp[idx];
       }
      
        int step1  = solve(n,idx+1,dp);
        int step2  = solve(n,idx+2,dp);

        return dp[idx]=step1+step2;


    }

    int climbStairs(int n) {
       int dp[46];
       memset(dp,-1,sizeof(dp));
       return solve(n,0,dp);
    }
};
