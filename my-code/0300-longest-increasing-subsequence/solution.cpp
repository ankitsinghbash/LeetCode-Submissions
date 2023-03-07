class Solution {
public:
 
    int solve(vector<int> &nums,int idx,int n,int prev,vector<vector<int>> &dp){

 
       if(idx==n){
           return 0;
       }
       
       if(dp[idx][prev+1]!=-1){
           return dp[idx][prev+1];
       }

       int pick=0;
       int notpick=0;
     //  notpick = 0+solve(nums,idx+1,n,prev,dp);
       if(prev==-1|| nums[idx]>nums[prev]){
           pick  = 1+solve(nums,idx+1,n,idx,dp);
       }
        notpick = 0+solve(nums,idx+1,n,prev,dp);
      return dp[idx][prev+1]=max(pick,notpick);

    }


    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(nums,0,n,-1,dp);
    }
};
