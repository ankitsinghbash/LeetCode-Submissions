class Solution {
public:
  long long solve(int idx,int x,vector<int> &nums,vector<vector<long long>> &dp){
   if(idx==nums.size()) return 0;

   if(dp[idx][x]!=-1) return dp[idx][x];
   
    long long skip = solve(idx+1,x,nums,dp);
    long long consider;
    if(x==0){
        consider = nums[idx]+solve(idx+1,1,nums,dp);
    }
    else{
        consider = -nums[idx]+solve(idx+1,0,nums,dp);
    }
   
     return  dp[idx][x] = max(skip,consider);

  }


    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size()+1,vector<long long>(2,-1));
        return solve(0,0,nums,dp);
    }
};
