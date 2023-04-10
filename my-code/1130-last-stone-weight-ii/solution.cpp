class Solution {
public:
  
  int knapsack(vector<int> &arr,int weight,int n,int idx,int cost,vector<vector<int>> &dp){
    if(idx>=n || weight<0){
        return 0;
    }
   
    if(dp[idx][weight]!=-1) return dp[idx][weight];

    int pick=0;
    int notpick = 0;
    notpick = knapsack(arr,weight,n,idx+1,cost,dp);
    if(arr[idx]<=weight){
         pick =arr[idx]+knapsack(arr,weight-arr[idx],n,idx+1,cost,dp);
    }
    cost+=max(pick,notpick);
    return dp[idx][weight]=cost;
  }


    int lastStoneWeightII(vector<int>& stones) {
         int totalsum = 0, n=stones.size();
        for (int i=0;i<stones.size();i++){
           totalsum += stones[i];
        }

        vector<vector<int>> dp(n+1,vector<int>(totalsum+1,-1));
        return totalsum-2*knapsack(stones,totalsum/2,n,0,0,dp);
        
    }
};
