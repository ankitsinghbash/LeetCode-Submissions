class Solution {
public:
   int solve(int i,int n1,int j,int m2,vector<int> &nums1,vector<int> &nums2,vector<vector<int>> &dp){
           if(i>=n1 || j>=m2){
               return 0;
           }
     
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
           
                 
            if(nums1[i]==nums2[j]){
                return  dp[i][j] = 1+solve(i+1,n1,j+1,m2,nums1,nums2,dp);
            }
            else{
                return dp[i][j] = max(solve(i+1,n1,j,m2,nums1,nums2,dp),solve(i,n1,j+1,m2,nums1,nums2,dp));
            }

   }
 



    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
          vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,-1));
          int i=0;
          int j = 0;
          int n1 = nums1.size();
          int m2 = nums2.size();
          return solve(i,n1,j,m2,nums1,nums2,dp);
    }
};
