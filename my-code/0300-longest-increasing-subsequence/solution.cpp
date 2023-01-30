class Solution {
public:

    int solve(vector<int> &nums,int idx,int prev,int n,int len,vector<vector<int>> &dp){
        
         if(idx==n) return 0;
  
        
         if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];

          //not taken the value;
         len = 0+solve(nums,idx+1,prev,n,len,dp);
         if(prev== -1 || nums[idx] > nums[prev]){ //condition of prev==-1 because if in start we not taken means current elemet of prev is also now at -1; if(nums[idx]>nums[prev] || prev == -1 ) //not work because order is matter compiler check from left to right: if any condition true to int loop:
             //taken  the value;
             len = max(len,1+solve(nums,idx+1,idx,n,len,dp));  //if we taken the value the prev become idx;
         }
         return dp[idx][prev+1]=len;

    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+2,-1));
        return solve(nums,0,-1,n,0,dp);
    }
};






//Tabulation method:

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         //Initial the dp with 1 beacuse minimum subsequece should be 1;........p
//         //formula if(nums[i]>nums[j])
//         //dp[i]=max(dp[i],dp[j]+1);  
//         int n=nums.size();
//         vector<int> dp(n,1);
//         for(int i=1;i<nums.size();i++)
//         {
//             int j=0;
//             while(j<i)
//             {
//                 if(nums[j]<nums[i])
//                 {
//                     dp[i]=max(dp[i],dp[j]+1);
//                 }
//                 j++;
//             }
//         }
//        //cout ki max in dp;
//        int ans=0;
//        for(int i=0;i<n;i++)
//        {
//             ans=max(ans,dp[i]);
//        }
//        return ans;
//     }
// };
