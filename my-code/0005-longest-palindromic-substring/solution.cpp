class Solution
 { 
     public: 
     string longestPalindrome(string s) { 
    vector<vector<int> > dp(2, vector<int>(s.size() + 10)); 
    int n = (int)s.size() - 1; 
    dp[0][n] = 1;
     int mxi = n, mxj = n; 
     bool last = 0; 
 for(int i = (int)s.size() - 2; i >= 0 ; --i)
      { 
    last = !last;
   for(int j = i; j < s.size(); ++j) 
   {
        if(i == j)
         dp[last][j] = 1;
        else if(j - i == 1)
      dp[last][j] = ((s[i] == s[j]) ? 1 : 0);
    else
  dp[last][j] = ((s[i] == s[j] && dp[!last][j - 1] == 1) ? 1 : 0);
   if(dp[last][j] == 1)
    {
        if(j - i > mxj - mxi)
         {
            mxj = j; mxi = i;
         }
         }
     } 
     }
 return s.substr(mxi, mxj - mxi + 1); 
 }
 };
