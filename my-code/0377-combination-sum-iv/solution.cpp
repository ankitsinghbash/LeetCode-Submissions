class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int > dp(target+1);
        dp[0]=1;
        for(int i=1;i<=target;i++)
           for(auto coin:nums)
                if(coin<=i)
                    dp[i]+=dp[i-coin];
        return dp[target];
    }
};
