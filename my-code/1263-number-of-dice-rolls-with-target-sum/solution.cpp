class Solution {
public:
   const long long mod = 1e9+7;
   int solve(int n,int range,int target,vector<vector<int>> &dp){
      if(target<0 || n<0 ){
          return 0;
      }

      if(n==0 && target==0){
          return 1;
      }
    
      if(dp[n][target]!=-1){
          return dp[n][target];
      }


      long long cnt=0;
      for(int i=1;i<=range;i++){
          cnt+=solve(n-1,range,target-i,dp)%mod;
      }


     return dp[n][target] = cnt%mod;

   }


    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
};
