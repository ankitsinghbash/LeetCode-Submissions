class Solution {
public:
    int countSubstrings(string s) {
        //Remember this type not required to get extra size like s.size()+1;
        int counter=0; //increase every counter when dp get true;
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size()));
       int count = 0;
      for (int g = 0; g < s.size(); g++) {
        for (int i = 0, j = g; j <s.size(); i++, j++) {
        if (g == 0) 
        {
          dp[i][j] = true;
        }
         else if (g == 1)
          {
          if (s.at(i) == s.at(j)) {
            dp[i][j] = true;
          } else {
            dp[i][j] = false;
          }
        }
         else
         {
          if (s.at(i) == s.at(j) && dp[i + 1][j - 1] == true)
           {
            dp[i][j] = true;
          }
           else 
           {
            dp[i][j] = false;
          }
        }

        if (dp[i][j])
         {
          count++;
         }
      }
    }
    return count;
    }
};




