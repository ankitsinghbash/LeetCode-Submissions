class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        
        int l = s3.length();
		
        if(m+n != l) return false;
        
        bool dp[m+1][n+1];
        
        for(int i=0; i<=m;++i){
            for(int j=0; j<=n; ++j){
                if(i==0 && j == 0) 
                    dp[i][j] = true;
                else if(i>0 && j>0 && s3[i+j-1] == s2[j-1] && s3[i+j-1] == s1[i-1])
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                else if(i>0 && s3[i+j-1] == s1[i-1])
                    dp[i][j] = dp[i-1][j];
                else if(j>0 && s3[i+j-1] == s2[j-1])
                    dp[i][j] = dp[i][j-1];
                else 
                    dp[i][j] = false;
            }
        }
        
        return dp[m][n];
    }   
};
