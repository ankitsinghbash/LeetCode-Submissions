class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        for(int i=1;i<nums.size();i++)
        {
            int j=0;
            while(j<i)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
                j++;
            }
        }
       //cout ki max in dp;
       int ans=0;
       for(int i=0;i<n;i++)
       {
            ans=max(ans,dp[i]);
       }
       return ans;
    }
  
    
};
