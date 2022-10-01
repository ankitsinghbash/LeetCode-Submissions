class Solution {
public:
    int dp[46];
    int climbStairs(int n) {

     //recursive wali condition in dp;   
    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<n+1;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
    }
};


 /*
      //I have only two option at each strairs:
      //Either i take 1's step or take 2's step:
      if(n==0||n==1)
      {
          return 1;
      }

      int first=climbStairs(n-1);
      int second=climbStairs(n-2);
      int ans=first+second;
      return ans;

    }
    */
