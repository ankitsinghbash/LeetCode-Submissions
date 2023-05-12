class Solution {
public:
  
   long long solve(int idx,vector<vector<int>> &box,vector<long long> &dp){
    
     if(idx>=box.size()) return 0;
     
      if(dp[idx]!=-1) return dp[idx];
    
      long long pick =0;
      long long notpick = 0;
      pick = box[idx][0] + solve(idx+box[idx][1]+1,box,dp);
      notpick = solve(idx+1,box,dp);
      return dp[idx] = max(pick,notpick);
   }



    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size()+1,-1);
        return solve(0,questions,dp);
    }
};
