class Solution {
public:
   int dp[301];
   int helper(int i,string s,set<string> &wordDic)
   {
      if(i==s.size()) return true;
      string path;
      if(dp[i]!=-1)
      {
          return dp[i];
      }

      for(int j=i;j<s.size();j++)
      {
          path+=s[j];
          //check is path is present in the wordDic or not:
          if(wordDic.find(path)!=wordDic.end())
          {
              //mean present then Ok:
              //now try to find as same according to next more element use of recursion:
              if(helper(j+1,s,wordDic))
              {
                  return dp[i]=true;
              }
          }
      }

     //if no word is found and i=0;
     return dp[i]=false;
   }
    
    bool wordBreak(string s, vector<string>& wordDict) {
    memset(dp,-1,sizeof dp);
    set<string> st;
    for(auto x:wordDict)
    {
        st.insert(x);
    }    
    return helper(0,s,st);
 
    }
};
