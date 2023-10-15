class Solution {
public:
   const int mod = 1e9+7;
   int dp[501][501];
   int solve(int i,int steps,int arrlen){


  
        if(i<0 || arrlen<=i){
            return 0;
        }

   if(steps==0){
       if(i==0){
           return 1;
       }
       return 0;
   }

   if(dp[i][steps]!=-1){
       return dp[i][steps];
   }
   
 
   
     
    long long  right = solve(i+1,steps-1,arrlen)%mod;
    long long left = solve(i-1,steps-1,arrlen)%mod;
    long long stay = solve(i,steps-1,arrlen)%mod;
    return  dp[i][steps] = (right%mod+left%mod+stay%mod)%mod;   

   }



    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        return solve(0,steps,arrLen);
    }
};
