class Solution {
public:

   long long  solve(vector<int> &nums,int n,int idx,vector<int> &dp){
 
      if(idx>=n-1){
          return 0;
      }
   
      if(dp[idx]!=-1){
          return dp[idx];
      }
     
      long long mini = INT_MAX;
      for(long long  i=1;i<=nums[idx];i++){
          long long ans = solve(nums,n,idx+i,dp)+1;
          mini=min(mini,ans);
      }
      return dp[idx]=mini;
   }

    int jump(vector<int>& nums) {
        long long n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(nums,n,0,dp);
    }
};
