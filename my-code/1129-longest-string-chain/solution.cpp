class Solution {
public:
  int dp[1001][1001];
  bool ispossible(string &word2,string &word1){
      if(word1.size()>=word2.size()) return false;
      if(word1.size()+1!=word2.size()) return false;

  
      int i=0;
      int j=0;
      int cnt=0;
      while(i<word1.size() && j<word2.size()){
          if(word1[i]==word2[j]){
              i++;
              j++;
          }
          else{
              j++;
              cnt++;
          }
      }

      while(j<word2.size()){
          j++;
          cnt++;
      }
      return cnt==1 ? true : false;

  }

  

   struct cmp{
       bool operator()(string &a,string &b){
           return a.size()<b.size();
       }
   };

    int solve(int idx,int prev,vector<string> &words){
        if(idx>words.size()){
            return 0;
        }
  
        if(dp[idx][prev]!=-1){
            return dp[idx][prev];
        }

        int notpick=0;
        int pick=0;
        notpick = solve(idx+1,prev,words);
        if(prev==0 || ispossible(words[idx-1],words[prev-1])){
            pick = 1+solve(idx+1,idx,words);
        }

        return dp[idx][prev] = max(pick,notpick);

    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp());
        memset(dp,-1,sizeof(dp));
        return solve(1,0,words);
    }
};
