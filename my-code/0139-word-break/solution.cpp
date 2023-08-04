class Solution {
public:
  int dp[301];
  bool solve(int idx,string s,unordered_set<string> &st){

     if(idx>=s.size()) return true;
   
     if(dp[idx]!=-1) return dp[idx];
   
     string path;
     for(int i=idx;i<s.size();i++){
          path+=s[i];
          if(st.find(path)!=st.end()){
               if(solve(i+1,s,st)==true){
                   return dp[idx] = true;
               }
          }
     }
      return dp[idx] = false;
  }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto x : wordDict){
          st.insert(x);
        }
         memset(dp,-1,sizeof(dp));
        return solve(0,s,st);

    }
};
