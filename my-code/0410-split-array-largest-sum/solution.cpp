class Solution {
public:

    int solve(int idx,int k,int n,vector<int> &nums,vector<vector<int>> &dp){

        if(k==1){
            int sum=0;
            for(int i=idx;i<n;i++){
                sum+=nums[i];
            }
            return sum;
        }
        
        if(dp[k][idx]!=-1){
            return dp[k][idx];
        }

        int sum=0;
        int mini = INT_MAX;
        for(int i=idx;i<=n-k;i++){
            sum+=nums[i];
            int total = max(sum,solve(i+1,k-1,n,nums,dp));
            mini = min(mini,total);
        }
        return dp[k][idx]=mini;


    }

    int splitArray(vector<int>& nums, int k) {
        //same question
       //  https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/
       
       int n=nums.size();
       vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
       return solve(0,k,n,nums,dp);
    }
};
