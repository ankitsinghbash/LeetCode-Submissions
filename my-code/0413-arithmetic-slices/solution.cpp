class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        vector<int> dp(n,0);   //vector<int> dp(n+1,-1); //use in memorization:
       
        
        for(int i=2;i<n;i++){
              if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                  dp[i]=dp[i-1]+1;
                  ans+=dp[i];
              }
        }
        for(auto &x : dp){
            cout<<x<<" ";
        }
        return ans;
        // for(auto &x : dp){   //count the sum in the dp else 0 and -1;
         //     if(x!=-1 && x!=0){
        //         ans+=x;
        //     }
        // }

     
        
    }
};
