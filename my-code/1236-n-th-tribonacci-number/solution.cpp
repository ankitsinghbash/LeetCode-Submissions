class Solution {
public:

   int solve(int n,int dp[]){
 
     if(n==0) return 0;
     if(n==1 || n==2) return 1;

     if(dp[n]!=-1) return dp[n];

     return dp[n]=solve(n-1,dp)+solve(n-2,dp)+solve(n-3,dp);
     
   }

    int tribonacci(int n) {
        //recursive+memo;
        int dp[38];
        memset(dp,-1,sizeof(dp));
        return solve(n,dp);
    }
};




//Tabulation:
// class Solution {
// public:

//    //this is recursive approach:
//    int solve(int n,int *dp)
//    {
//        dp[0]=0;
//        dp[1]=1;
//        dp[2]=1;
//        for(int i=3;i<=n;i++)
//        {
//            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
//        }
//       return dp[n];
//    }

//     int tribonacci(int n) {
//         //first solve by recursion:
//         int dp[n+3]; 
//         int ans=solve(n,dp);
//         return ans;
//     }
// };


