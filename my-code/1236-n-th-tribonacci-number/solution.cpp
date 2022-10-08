class Solution {
public:

   //this is recursive approach:
   int solve(int n,int *dp)
   {
       dp[0]=0;
       dp[1]=1;
       dp[2]=1;
       for(int i=3;i<=n;i++)
       {
           dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
       }
      return dp[n];
   }

    int tribonacci(int n) {
        //first solve by recursion:
        int dp[n+3];
        int ans=solve(n,dp);
        return ans;
    }
};


/*
Now the approch is right do with dynammic prorgramming:
//this is recursive approach:
   int solve(int n)
   {
       if(n==0)
       {
           return 0;
       }
       if(n==1||n==2)
       {
           return 1;
       }
  
      int answer=solve(n-1)+solve(n-2)+solve(n-3);
      return answer;

   }

*/
