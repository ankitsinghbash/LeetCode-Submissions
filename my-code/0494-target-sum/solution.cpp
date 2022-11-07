class Solution {
public:
    
int subsetsumcount(vector<int> a, int n, int sum)
{
    // Initializing the matrix
    int dp[n + 1][sum + 1];
  // Initializing the first value of matrix
    dp[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;
     
   
    for (int i = 1; i <n+1; i++)
    {
        for (int j = 0; j <sum+1; j++)
        {
          // if the value is greater than the sum
            if (j>=a[i-1]){
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}


    int findTargetSumWays(vector<int>& nums, int target) {
         int sum=0;
        for(int i=0;i<nums.size();i++)
        {
         sum+=nums[i];
        }
        //base case: //problem same to count the subset that give the given target but check base case:
        if (abs(target) > sum || (sum + target) % 2 != 0){ 
            return 0;
        }
        int n=nums.size();
	    int reqSum=(target+sum)/2;
	    return subsetsumcount(nums,n,reqSum);
    }
};
