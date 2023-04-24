class Solution {
public:
   int const MOD = 1e9+7;
   int solve(int i,int n,int &k,int target,vector<vector<int>> &dp){
     if(i==0){
         if(target==0){
             return 1;
         }
         else{
             return 0;
         }
     }
     if(target<0){
         return 0;
     }

     if(dp[i][target]!=-1){
         return dp[i][target];
     }
   

       long long ans=0;
       for(int j=1;j<=k;j++){
               ans=(ans+solve(i-1,n,k,target-j,dp))%MOD;
       }
      return dp[i][target] =  ans%MOD;
   }
   
    
 
    int numRollsToTarget(int n, int k, int target) {
        int i=n;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(i,n,k,target,dp);
    }
};
