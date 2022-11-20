class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()));
        int su = 0;
        for(auto x : nums)
        {
            su+=x;
        }

        for(int g=0;g<nums.size();g++)
        {
            for(int i=0,j=g;j<nums.size();i++,j++)
            {
                if(g==0)
                {
                    dp[i][j]=nums[i];
                }
                else if(g==1)
                {
                    dp[i][j]=max(nums[i],nums[j]);
                }
                else{
                    int val1  = nums[i]+min(dp[i+2][j],dp[i+1][j-1]);
                    int val2 =  nums[j]+min(dp[i+1][j-1],dp[i][j-2]);
                    int val = max(val1,val2);
                    dp[i][j]=val;
                }
            }
           
        }
        return dp[0][nums.size()-1]>=su-dp[0][nums.size()-1];
    }
     
};
