class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned int>> dp(t.size()+1,vector<unsigned int>(s.size()+1));

        for(int j=0;j<s.size()+1;j++)
        {
            dp[0][j]=1;
        }
    
        for(int i=1;i<t.size()+1;i++)
        {
            dp[i][0]=0;
        }
     
        for(int i=1;i<t.size()+1;i++)
        {
            for(int j=1;j<s.size()+1;j++)
            {
                if(t[i-1]==s[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                }
                else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
         return dp[t.size()][s.size()];
    }
};

/*matrix: //base:
   0th 1th
   b  a  b  g  b  a  g  -->s
   1  1  1  1  1  1  1 
b  0
a  0
g  0
|
|
t
if(t[i-1]==s[j-1])
{
    dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
}
else
{
    dp[i][j]=dp[i][j-1];
}
*/





