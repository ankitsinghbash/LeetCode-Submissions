class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[n+1][amount+1];
        //fix karo 1st col:
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=1;
        }

        //fix 1st row:
        for(int j=1;j<amount+1;j++)
        {
            dp[0][j]=0;
        }

       for(int i=1;i<n+1;i++)
       {
           for(int j=1;j<amount+1;j++)
           {
               if(j>=coins[i-1])  //amount greater then or equal coin size:
               {
                    dp[i][j]=dp[i][j-coins[i-1]]+dp[i-1][j];  //prev case + above case:
               }
               else
               {
                   //amount is lesser then coin size: //when amount hi kaam ho then copy above case of table:
                   dp[i][j]=dp[i-1][j];
               }
           }
       }
       return dp[n][amount];
    }
};
