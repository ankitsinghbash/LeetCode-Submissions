class Solution {
public:
    int dp[2501][2501];
    int solve(int idx,int prev,vector<int> &nums){
       if(idx>nums.size()){
           return 0;
       }
  
       if(dp[idx][prev]!=-1){
           return dp[idx][prev];
       }

       int pick=0;
       int notpick=0;
       notpick = solve(idx+1,prev,nums);
       if(prev==0 || nums[idx-1]>nums[prev-1]){
            pick =  1+solve(idx+1,idx,nums);
       }

       return dp[idx][prev] = max(pick,notpick);

    }
    int lengthOfLIS(vector<int>& nums) {
        //using recursion: 
        memset(dp,-1,sizeof(dp));
        return solve(1,0,nums);
    }
};
