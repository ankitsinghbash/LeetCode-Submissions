class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int dp[n+1][m+1];
        dp[0][0]=0;
        for(int i=1;i<n+1;i++)  //means word1 row me hai:
        {
            dp[i][0]=i;
        }
        for(int j=1;j<m+1;j++)   //means word2 col me hai:
        {
            dp[0][j]=j;
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
                }
            }
        }
        return dp[n][m];



    }
};
