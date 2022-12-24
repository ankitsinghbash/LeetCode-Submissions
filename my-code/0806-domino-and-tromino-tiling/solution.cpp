class Solution {
public:
    int numTilings(int n) {
        vector<int> dp(n+1);
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 5;

        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        int mod =  1000000007;
        for(int i=4;i<n+1;i++){
            dp[i]=((2*dp[i-1]%mod)+(dp[i-3]%mod))%mod;  //formula:
        }
        return dp[n];
        
    }
};
