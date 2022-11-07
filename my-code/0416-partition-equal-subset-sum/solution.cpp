class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //100% similar to subset sum target problem
        //https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1   //subset gfg problem:
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        int dp[n+1][sum/2+1];
  
        if(sum%2!=0) return false;  //if sum is odd:
        dp[0][0]=false;
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=true;
        }

        for(int j=0;j<sum/2+1;j++)
        {
            dp[0][j]=false;
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum/2+1;j++)
            {
                if(j>nums[i-1])   //when j mean sum > arr[i-1] se or equal to then above or negative wale ka or 
                {
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
                }
                else if(nums[i-1]==j)  //only extra condition when subset mill gya then direct add true in dp:
                {
                    dp[i][j]=true;
                }
                else
                {
                    //copy above wala:
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
       return dp[n][sum/2];
    }
};
