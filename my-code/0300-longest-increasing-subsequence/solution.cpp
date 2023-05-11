class Solution {
public:
   int solve(int idx,int prev,vector<int> &nums,vector<vector<int>> &dp){
       if(idx>nums.size()){
           return 0;
       }

       if(dp[idx][prev]!=-1){
           return dp[idx][prev];
       }

       int pick=0;
       int notpick=0;
       notpick = solve(idx+1,prev,nums,dp);
       if(prev == 0 || nums[idx-1]>nums[prev-1]){
           pick = 1+solve(idx+1,idx,nums,dp);
       } 
       return dp[idx][prev] = max(pick,notpick);
   }




    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,0,nums,dp);
    }
};
