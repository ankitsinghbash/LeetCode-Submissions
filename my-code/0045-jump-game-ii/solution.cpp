class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size());
        for(int i=nums.size()-2;i>=0;i--)
        {
            int step=nums[i];
            int mini=INT_MAX;
            if(step>0)
            {
               for(int j=1;j<=step && i+j<nums.size();j++)
               {
                   mini=min(mini,dp[i+j]);
              }
            }
            if(mini==INT_MAX)
            {
                dp[i]=mini;
            }
            else
            {
                dp[i]=mini+1;
            }
        }
        return dp[0];
    }
};



