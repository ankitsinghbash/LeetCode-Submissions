class Solution {
public:
    bool check(int cur, int idx, int len, vector<vector<vector<bool>>>&dp,vector<int>&nums){
        if(len == 0) return cur == 0;
        if(idx == nums.size() || cur<0) return false;
        
        if(dp[idx][len][cur]!=true) return dp[idx][len][cur];
        return dp[idx][len][cur]=check(cur-nums[idx], idx+1, len-1, dp, nums) || check(cur, idx+1, len, dp, nums);
    
    }
    
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i:nums) sum+=i;
        vector<vector<vector<bool>>>dp(n+1, vector<vector<bool>>(n+1, vector<bool>(sum+1, true)));
        for(int i = 1; i <= n-1; i++) if((sum*i)%n == 0) if(check((sum*i)/n, 0, i, dp, nums)) return true;
        return false;
    }
};
