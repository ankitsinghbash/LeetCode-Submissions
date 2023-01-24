class Solution {
public:
   int solve(vector<int> &nums,int idx,int n,vector<int> &dp){
    if(idx>=n){
        return 0;
    }

    if(dp[idx]!=-1){
        return dp[idx];
    }

     int pick = nums[idx]+solve(nums,idx+2,n,dp);
     int notpick = solve(nums,idx+1,n,dp);
     return dp[idx]=max(pick,notpick);
     
   }

    int rob(vector<int>& nums) {
    
        int n = nums.size();
        if(n==0){
            return 0;
        }
         if(n==1){
             return nums[0];
         }
    

        
        
       vector<int> dp1(n+1,-1) , dp2(n+1,-1);
        int first = solve(nums,0,n-1,dp1); 
   
        int second = solve(nums,1,n,dp2);
        return max(first,second); 
    }
};
