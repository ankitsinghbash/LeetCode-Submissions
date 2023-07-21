class Solution {
public:
    int dp[501][501];
    int solve(int idx1,int idx2,string &word1,string word2){
      if(idx2>=word2.size()) return word1.size()-idx1;
      if(idx1>=word1.size()) return word2.size()-idx2;
       
       if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

       if(word1[idx1]==word2[idx2]){
            return solve(idx1+1,idx2+1,word1,word2);
        }

      int op1=0,op2=0,op3=0;
      op1=solve(idx1+1,idx2,word1,word2);
      op2=solve(idx1,idx2+1,word1,word2);
      op3=solve(idx1+1,idx2+1,word1,word2);

      return dp[idx1][idx2] = min({op1,op2,op3})+1;

    }

    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
       return solve(0,0,word1,word2);
    }
};
