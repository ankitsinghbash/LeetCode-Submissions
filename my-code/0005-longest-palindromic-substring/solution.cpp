class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size()));
    
        int start;
        int last;
        for(int g=0;g<s.size();g++){
            for(int i=0,j=g;j<s.size();i++,j++){
                if(g==0){
                   dp[i][j]=true;
                }
                else if(g==1){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
                else{
                     if(s[i]==s[j] && dp[i+1][j-1]==true){
                         dp[i][j]=true;
                     }
                     else{
                         dp[i][j]=false;
                     }
                }

                if(dp[i][j]==true){
                    start=i;
                    last=j;
                }
            }
        }

        string str = s.substr(start,last-start+1);
        return str;

    }
};
