class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int dp[n+1][amount+1];
        for(int i=0;i<n+1;i++)   //loop for coin: i->coin:
        {
            for(int j=0;j<amount+1;j++)   //loop for amount: j->amount:
            {
                if(j==0)   //amount:
                {
                    dp[i][j]=0;
                }
                else if(i==0)    //coin 0;
                {
                    dp[i][j]=1e5;
                }
                else if(coins[i-1]>j)  //jab taak coin is not greater then amount:
                {
                     dp[i][j]=dp[i-1][j];  //exclusive case:
                }
                else{
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]); //inclusive case:
                }
            }
        }
        if(dp[n][amount]==1e5)
        {
            return -1;
        }
        else{
            return dp[n][amount];
        }
    }
};



/*
2D dp matrix:
if give the minimum coin required to make a target amount:
//This is given for example 1,2,5 as a coin and target amount is 11:

idx->0, 1 ,2, 3, 4, 5, 6, 7, 8, 9, 10 ,11   -> there are amount:
  0 ,0 ,M ,M ,M ,M ,M ,M ,M ,M ,M , M, M     ->M denote infinite:
  1 ,0 ,1 ,2, 3 ,4 ,5 ,6 ,7 ,8 ,9, 10, 11
  2 ,0 ,1 ,1, 2 ,2 ,3 ,3 ,4 ,4 ,5,  5, 6 
  5, 0 ,1, 1, 2 ,2 ,1 ,2 ,2 ,3 ,3,  2, 3
  ^
  |
 idx
//hence if dp[n][amount]==M return -1:
else return dp[n][amount] -> Give the ans:
*/

