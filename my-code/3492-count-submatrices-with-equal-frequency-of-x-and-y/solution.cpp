class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& g) {
        int n = g.size();
        int m = g[0].size();
        int ans=0;
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(m,{0,0}));
        vector<vector<pair<int,int>>> grid(n,vector<pair<int,int>>(m));
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]=='X'){
                     grid[i][j] = {1,0};
                }
                else if(g[i][j]=='Y'){
                    grid[i][j] = {0,1};
                }
                else{
                    //for {.}
                    grid[i][j] = {0,0};
                }
            }
        }
        
        
         
        dp[0][0] = grid[0][0];
        for(int i=1;i<n;i++){
              int x  = dp[i-1][0].first+grid[i][0].first;
              int y =  dp[i-1][0].second+grid[i][0].second;
              dp[i][0] = {x,y};
             if(dp[i][0].first!=0){
                         if(dp[i][0].first==dp[i][0].second){
                             ans++;
                         }
                     }
        }
        
        for(int j=1;j<m;j++){
             int x = dp[0][j-1].first+grid[0][j].first;
            int y  = dp[0][j-1].second + grid[0][j].second;
             dp[0][j] = {x,y};
             if(dp[0][j].first!=0){
                         if(dp[0][j].first==dp[0][j].second){
                             ans++;
                         }
                     }
        }
         
        
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                
                     int x = grid[i][j].first  +   dp[i][j-1].first+(dp[i-1][j].first-dp[i-1][j-1].first);
                     int y = grid[i][j].second + dp[i][j-1].second+(dp[i-1][j].second-dp[i-1][j-1].second);
                     dp[i][j]  = {x,y};
                
                     if(dp[i][j].first!=0){
                         if(dp[i][j].first==dp[i][j].second){
                             ans++;
                         }
                     }
            }
        }
       return ans;
        
        
    
    }
};
