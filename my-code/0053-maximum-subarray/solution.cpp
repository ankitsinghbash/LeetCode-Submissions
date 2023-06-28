class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0]=nums[0];
        int maxx = nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=max(nums[i],dp[i-1]+nums[i]);
            maxx = max(maxx,dp[i]);
        }
        return maxx;
    }
};
