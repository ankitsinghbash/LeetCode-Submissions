class Solution {
public:
   const int mod = 1e9+7;
   int solve(vector<int> &locations,int start,int finish,int fuel,vector<vector<int>> &dp){
       
       if(fuel<0) return 0;

    
       if(dp[start][fuel]!=-1){
           return dp[start][fuel];
       }


       int ans=0;
       if(start==finish){
           ans++;
       }

       for(int idx=0;idx<locations.size();idx++){
           if(idx!=start){
                ans=(ans%mod+solve(locations,idx,finish,fuel-abs(locations[start]-locations[idx]),dp)%mod)%mod;
           }
       }
     return  dp[start][fuel] =  (ans%mod);     
   }





    int countRoutes(vector<int>& locations, int start, int finish, int fuel){
        vector<vector<int>> dp(locations.size(),vector<int>(fuel+1,-1));
        return solve(locations,start,finish,fuel,dp);
    }
};
