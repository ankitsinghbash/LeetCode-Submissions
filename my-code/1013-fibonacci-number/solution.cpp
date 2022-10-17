/*
class Solution {
public:
    
    int helper(int n)
    {
        if(n==0||n==1)
        {
            return n;
        }
        
      int ans=helper(n-1)+helper(n-2);
      return ans;
    }

    int fib(int n) {
         int solution = helper(n); 
         return solution;
    }
};

*/


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
