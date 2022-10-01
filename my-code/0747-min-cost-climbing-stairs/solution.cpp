class Solution {
public:
    int solve(vector<int> &cost,int n,vector<int> &dp)
    {
        if(n==0||n==1)  //in top down approach jab 0 or 1 par gya to direct cost return kardi no need to define cost at 0 and 1 because it a top down approch:
          return cost[n];

        if(dp[n]!=-1)  //when dp[n]!=-1 //mean ans dp me hai hence return dp[n] as a and:
         return dp[n];

         dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
         return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size();
    vector<int> dp(n+1,-1);  //Initialize the all dp space with -1;
    int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
    return ans;
    }
};



 /*
    //bottom up approach:
    int n=cost.size();
    vector<int> dp(n+1);  //also taken dp size as dp(n);
    dp[0]=cost[0];
    dp[1]=cost[1];

    for(int i=2;i<n;i++)
    {
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]); //current cost + previous wali ki minimum 
    }
      //Last two given the minimum cost:
      return min(dp[n-1],dp[n-2]);

    }
    */

