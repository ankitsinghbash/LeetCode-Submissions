
class Solution {
public:
    int helper(int n,unordered_map<int,int> &dp)
    {
        if(n==0||n==1)
        {
            return n;
        }

      if(dp.find(n)!=dp.end()){
          return dp[n];
      }
        
      int ans=helper(n-1,dp)+helper(n-2,dp);
      return dp[n]=ans;
    }

    int fib(int n) {
        unordered_map<int,int> dp;
         int solution = helper(n,dp); 
         return solution;
    }
};



/*

class Solution {
public:
    int fib(int n) {
        int dp[n+2];   //this is helpful when user input the value n=0: so always allign in range:
         dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
*/
