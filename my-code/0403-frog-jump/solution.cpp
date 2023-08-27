class Solution {
public:
    bool canCross(vector<int>& stones) {
         int n = stones.size();
         if(stones[1]!=1) return false;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        dp[0][0] = true;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = stones[i] - stones[j];
                 if(diff>=n){ //diff is size n as dp initialze:
                     continue;
                 }
                if(dp[j][diff] or (diff-1>=0 and dp[j][diff-1]) or (diff+1<n and dp[j][diff+1])){
                    dp[i][diff] = true;
                }
            }
        }
        for(int j=0;j<n;j++){
            if(dp[n-1][j]){
                return true;
            }
        }
        return false;
    }
};
