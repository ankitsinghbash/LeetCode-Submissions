class Solution {
public:    
    bool canJump(vector<int>& nums) {
        //down top dp;
        int n=nums.size();
        vector<bool> dp(n+1,false);
        //let's we reache's the last index:
        dp[n-1]=true;  
        for(int i=n-2;i>=0;i--)
        {
            //we jum from 1 to nums[i]: and i+j<n;
           for(int j=0;j<=nums[i]&&i+j<n;j++)
           {
               if(dp[i+j]==true)
               {
                   dp[i]=true;
                   break;
               }
           }
        }

       return dp[0];
    }
};
