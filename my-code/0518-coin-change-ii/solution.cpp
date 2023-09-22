class Solution {
public:
    int dp[301][5001];
    int solve(int i,int amount,vector<int> &coins){
        if(i>=coins.size()) return 0;

        if(amount==0){
            return 1;
        }

        if(amount<0){
            return 0;
        }

        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }

        int pick = solve(i,amount-coins[i],coins);
        int notpick = solve(i+1,amount,coins);

        return dp[i][amount] = pick+notpick;

    
    }

    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return solve(0,amount,coins);
    }
};

// class Solution {
// public:
//     //this also count the duplicate:
//             //1+2+2 ==1 and 2+2+1 ==1 they count there are two diff but we required unique possible://means in this we go backward of array:
//             //and i case of taken or not taken we always go in the forward direction of array:
//     int solve(int amount, vector<int>& coins, vector<vector<int>>& dp) {
//         if (amount == 0) {
//             return 1;
//         }
        
//         if (amount < 0) {
//             return 0;
//         }

//         if (dp[amount][coins.size()] != -1) {
//             return dp[amount][coins.size()];
//         }

//         int cnt = 0;
//         for (int i = 0; i < coins.size(); i++) {
//             int rest = solve(amount - coins[i], coins, dp); 
//             cnt += rest;
//         }

//         dp[amount][coins.size()] = cnt;
//         return cnt;
//     }

//     int change(int amount, vector<int>& coins) {
//        // vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, -1));
//         return solve(amount, coins, dp);
//     }
// };

