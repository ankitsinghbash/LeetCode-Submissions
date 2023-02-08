class Solution {
public:
  
   long long solve(vector<int> &nums,int n,int idx,long long ans,vector<int> &dp){
 
       if(idx>=n-1){
           return 0;  //at last index 0 jump:
       }
 
      if(dp[idx]!=-1){
          return dp[idx];
      }

        long long  mini = INT_MAX;
        for(int i=1;i<=nums[idx];i++){
            ans = 1+solve(nums,n,idx+i,ans,dp);
            mini = min(mini,ans);
        }
 
       return dp[idx]=mini;
   }
 
 
    int jump(vector<int>& nums)  {
        
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(nums,n,0,0,dp);
    }
};
