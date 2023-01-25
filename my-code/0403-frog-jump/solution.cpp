class Solution {
public:

   bool solve(vector<int> &stones,int idx,int prev,int n,vector<vector<int>> &dp){

      if(idx == n-1) return true;
      if(idx >= n) return false;

      if(dp[idx][prev]!=-1) return dp[idx][prev];

      int prev_jump = stones[idx]-stones[prev];
      for(int i=idx+1;i<n;i++){
          int currjump = stones[i]-stones[idx];
          if(prev_jump-1==currjump||prev_jump==currjump||prev_jump+1==currjump){
              if(solve(stones,i,idx,n,dp)){
                  return dp[idx][prev]=true;
              }
          }
      }

      return dp[idx][prev]=false;

   }

    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) return false;

        int n = stones.size();
        int current = 1;
        int prev = 0;
        vector<vector<int>> dp(n,vector<int>(n,-1));  //change value are current and prev;
        return solve(stones,current,prev,n,dp);

    }
};
