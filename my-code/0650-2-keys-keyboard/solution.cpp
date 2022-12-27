class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<n+1;i++){
            for(int j=2;j<=i;j++)
            {
                   if(i%j==0){
                    int k = i/j;
                    dp[i]=min(dp[i],dp[k]+j);
                   }
            }
        }
        return dp[n];

    }
};
