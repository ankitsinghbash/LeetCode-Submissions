class Solution {
public:
    int dp[11][301];
    int solve(int start,vector<int> &jobDiff,int d,int n){
         if(d==1){
             int maxx = INT_MIN;
             for(int i=start;i<n;i++){
                 maxx = max(maxx,jobDiff[i]);
             }
             return maxx;
         }
        
        if(dp[d][start]!=-1){
            return dp[d][start];
        }
        
        int maxx = INT_MIN; 
        int mini = INT_MAX;
        for(int i=start;i<=n-d;i++){
              maxx = max(maxx,jobDiff[i]);
              int val = maxx+solve(i+1,jobDiff,d-1,n);
              mini = min(mini,val);
        }
        return dp[d][start] = mini;
          
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        memset(dp,-1,sizeof(dp));
        if(d>n) return -1;
        return solve(0,jobDifficulty,d,n);
    }
};
