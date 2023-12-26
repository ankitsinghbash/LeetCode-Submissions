class Solution {
public:
    typedef long long ll;
    const int mod = 1e9+7;
    int dp[31][1001];
    int solve(int n,int &k,int target){
          if(target<0){
              return 0;
          }

          if(n<0) return 0;

          if(n==0 && target==0){
              return 1;
          }
        
          if(dp[n][target]!=-1){
              return dp[n][target];
          }

          ll cnt=0;
          for(int i=1;i<=k;i++){
              cnt=(cnt+solve(n-1,k,target-i))%mod;
          }
          return dp[n][target] = cnt%mod;

    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k,target);
    }
};
