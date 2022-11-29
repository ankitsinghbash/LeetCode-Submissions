class Solution {
public:
    int integerBreak(int n) {
        //int n=nums.size();
      if(n==1) return n;

       vector<int> dp(n+1);
       dp[1]=1;
       for(int i=2;i<n+1;i++)
       {
          int maxi=INT_MIN;
          for(int j=1;j<i;j++)
          {
              int maxx = max(j,dp[j])*max(i-j,dp[i-j]);
              maxi=max(maxi,maxx);
          }   
          dp[i]=maxi;

       }
       return dp[n];


    }
};


   
