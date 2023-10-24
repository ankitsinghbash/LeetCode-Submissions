class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum/2+1));
        if(sum%2!=0){
            return false;
        }
        int n = nums.size();
        for(int i=0;i<n+1;i++){
            dp[i][0] = true;
        }
        for(int j=0;j<sum/2+1;j++){
            dp[0][j]=false;
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum/2+1;j++){
                if(j>nums[i-1]){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else if(j==nums[i-1]){
                    dp[i][j]=true;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][sum/2];
    }
};
