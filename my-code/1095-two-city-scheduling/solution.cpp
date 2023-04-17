class Solution {
public:
    
    long long solve(int i,int a,int b,vector<vector<int>> &costs,vector<vector<vector<int>>> &dp){
        
         if(i==costs.size() && a==0 && b==0){
             return 0;
         }
        
         if(a<0 || b<0) return INT_MAX;
         
         if(dp[i][a][b]!=-1) return dp[i][a][b];
        
         int sum=0;
         long long  taken_city_a = costs[i][0]+solve(i+1,a-1,b,costs,dp);
         long long taken_city_b = costs[i][1]+solve(i+1,a,b-1,costs,dp); 
         sum+=min(taken_city_a,taken_city_b);
         
         return dp[i][a][b]=sum;
    }
    
    
    
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        //SECOND APPROACH OF DP;
        int n = costs.size()/2;
        int a=n;
        int b=n;
        int i=0;
        vector<vector<vector<int>>> dp(costs.size()+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return solve(i,a,b,costs,dp);
    }
};
