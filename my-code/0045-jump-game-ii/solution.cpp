class Solution {
public:
  
   int dp[10001];
   long long solve(int start,int n,vector<int> &nums){
     if(start>=n-1){
         return 0;
     }
     
     if(dp[start]!=-1){
         return dp[start];
     }

     long long mini=INT_MAX;
     for(int k=1;k<=nums[start];k++){
         long long ans=1+solve(start+k,n,nums);
         mini=min(ans,mini);
     }
     return dp[start] = mini;

   }
   

    int jump(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,nums);
    }
};
