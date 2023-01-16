class Solution {
public:
   
   int solve(int idx,vector<int> &jd,int d,int n,vector<vector<int>> &dp){
       if(d==1){
               int maxx = INT_MIN;
               for(int i=idx;i<n;i++){
                   maxx = max(maxx,jd[i]);
               }
               return maxx;
       }

      if(dp[idx][d]!=-1){
          return dp[idx][d];
      }

      int maxx = INT_MIN;
      int finalans =  INT_MAX;

      for(int i=idx;i<=n-d;i++){
           maxx = max(maxx,jd[i]);
           int result = maxx + solve(i+1,jd,d-1,n,dp);

           finalans = min(result,finalans);
      }
      return dp[idx][d]=finalans;

   }

    int minDifficulty(vector<int>& jd, int d) {
        
        int n= jd.size();
        vector<vector<int>> dp(n+1,vector<int>(d+1,-1));
        if(n<d){
            return -1;
        }
        int ans = solve(0,jd,d,n,dp);
        return ans;
    }
};
