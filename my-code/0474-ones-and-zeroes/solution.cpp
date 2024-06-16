class Solution {
public:

     int solve(int i,int m,int n,vector<string> &strs,int zero,int one,vector<vector<vector<int>>> &dp){
       
         if(zero>m || one>n){
          return -1;
       }

       if(i>=strs.size()){
        return 0;
       }

        int z=0;
        int o=0;
        for(int j=0;j<strs[i].size();j++){
            if(strs[i][j]=='1'){
                o++;
            }
            else{
                z++;
            }
        }

          if(dp[i][zero][one]!=-1){
            return dp[i][zero][one];
        }

       

       
          
         int taken = 1+solve(i+1,m,n,strs,zero+z,one+o,dp);
         int nottaken = solve(i+1,m,n,strs,zero,one,dp);

         return dp[i][zero][one]  = max(taken,nottaken);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        //now apply dp:
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));

         int zero=0;
         int one =0;
         return solve(0,m,n,strs,zero,one,dp);
        
    }
};
