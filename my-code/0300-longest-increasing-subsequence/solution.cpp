class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            int maxx=1;
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                 int value = max(dp[i],dp[j]+1);
                 maxx = max(maxx,value);
                }
            }
            dp[i]=maxx;
        }
         
        int maxx = INT_MIN;
        for(int i=0;i<n;i++){
            maxx = max(maxx,dp[i]);
        }
        return maxx;

    }
};
