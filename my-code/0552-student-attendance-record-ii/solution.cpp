class Solution {
public:
    int mod = 1e9+7;    //Carefully seen it independent of present day so not use present day p as in memorization:
   int dp[100001][2][3];
    int solve(int p,int n,int a,int l){
        if(a==2||l==3)return 0;

        if(n==0)return 1;

        if(dp[n][a][l]!=-1) return dp[n][a][l];
        
        long long int ans = 0;
        ans = (ans+solve(p+1,n-1,a,0)%mod)%mod;  
        ans = (ans+solve(p,n-1,a+1,0)%mod)%mod;
        ans = (ans+solve(p,n-1,a,l+1)%mod)%mod;
        return dp[n][a][l] =  ans;
    }
    int checkRecord(int n) {

       memset(dp,-1,sizeof(dp));
        return solve(0,n,0,0);
    }
};
