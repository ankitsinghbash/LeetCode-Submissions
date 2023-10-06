class Solution {
public:
    long long solve(int n,vector<int> &dp){

        if(n==0){
            return 1;
        }
 
        if(n<0){
            return 0;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

  
        long long maxx=INT_MIN;
        for(long long i=1;i<=n;i++){
            long long prd = i*solve(n-i,dp);
            maxx = max(maxx,prd);
        }
        return dp[n] = maxx;

    }
    int integerBreak(int n) {
         if(n<4){
             return n-1;
         }
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};


