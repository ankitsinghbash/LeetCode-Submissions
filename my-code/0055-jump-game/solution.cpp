class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,false);
        dp[n-1]=true;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==0) continue;
            int step = nums[i];
            bool flag=false;
            for(int j=1;j<=step;j++){
                 if(i+j<nums.size()){
                   if(dp[i+j]==true){
                     flag=true;
                     break;
                   }
                 }
            }
            if(flag==true){
              dp[i]=true;
            }
            else{
              dp[i]=false;
            }
        }
        return dp[0];

    }
};
