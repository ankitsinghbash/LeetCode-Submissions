class Solution {
public:
    const int MOD = 1e9+7;
    int solve(int val,int low,int high,int zero,int one,vector<int> &dp){
       if(val>high) return 0;

    
       if(dp[val]!=-1) return dp[val];

       bool addOne = false;
       if(val>=low && val<=high) {
           addOne = true;
       }

       int left = solve(val+zero,low,high,zero,one,dp);
       int right = solve(val+one,low,high,zero,one,dp);

       return   dp[val] = (addOne + left + right)%MOD;
    }


    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,-1);
        return solve(0,low,high,zero,one,dp);
    }
};
