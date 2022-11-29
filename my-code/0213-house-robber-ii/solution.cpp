class Solution {
public:

   int solve1(vector<int> nums)
   {
       int n = nums.size();
       if(n==0) return 0;
       if(n==1) return nums[0];


      
       vector<int> dp(n+1,0);
       dp[1]=nums[0];
       for(int i=2;i<n+1;i++)
       {
           dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
       }
      return dp[n];
   }

    int rob(vector<int>& nums) {
       int n=nums.size();
       if(n==0) return 0;
       if(n==1) return nums[0];


        //answer max(0 to n-2 to 1 to n-1);
        vector<int> nums1(nums.begin(),nums.end()-1);
        vector<int> nums2(nums.begin()+1,nums.end());
        int ans = max(solve1(nums1),solve1(nums2));
        return ans;
    }
};
