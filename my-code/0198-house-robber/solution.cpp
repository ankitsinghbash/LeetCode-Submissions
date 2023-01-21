class Solution {
public:

   int solve(vector<int> &nums,int n,int idx,vector<int> &dp){

        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1)
             return dp[idx];
      
         int pick = nums[idx]+solve(nums,n,idx+2,dp);
         int notpick = solve(nums,n,idx+1,dp);
          
         return dp[idx]=max(pick,notpick);
   }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(nums,n,0,dp);
        
    }
};
