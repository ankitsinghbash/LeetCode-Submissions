class Solution {
public:
    int dp[2500][2500];
    int solve(int prev,int i,vector<int> &nums){
          //base case:
          if(i>=nums.size()) return 0;
         if(dp[prev+1][i]!=-1){
             return dp[prev+1][i];
         }
          int taken=0;
          int nottaken=0;
          if(prev==-1 || nums[prev]<nums[i]){
            taken =  1+solve(i,i+1,nums);
          }
         nottaken = solve(prev,i+1,nums);
         return dp[prev+1][i] =  max(taken,nottaken);

    }
    int lengthOfLIS(vector<int>& nums) {
        //if(nums[i]>nums[j]) means dp[i]=max(dp[i],dp[j]+1):
        memset(dp,-1,sizeof(dp));
      return solve(-1,0,nums);
    }
};
