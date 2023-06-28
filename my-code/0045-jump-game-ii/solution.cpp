class Solution {
public:
    int jump(vector<int>& nums) {

        //tabulation:
        int n = nums.size();
        vector<int> dp(nums.size(),0);
        for(int i=n-2;i>=0;i--){
               int mini = INT_MAX;
               int step = nums[i];
               if(step>0){
                   for(int j=1;j<=step;j++){
                       if(i+j<nums.size()){
                           mini = min(mini,dp[i+j]);
                       }
                   }
               }
               if(mini==INT_MAX){
                    dp[i]=mini;
               }
               else{
                   dp[i]=mini+1;
               }

        }
        return dp[0];
    }
};
