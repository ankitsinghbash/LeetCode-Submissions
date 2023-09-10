class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(1001,0);
        dp[0]=1;
        for(int i=1;i<target+1;i++){
            for(auto coins : nums){
                if(i>=coins){
                    dp[i] = dp[i] +dp[i-coins];
                }
            }
        }
        return dp[target];
    }
};
