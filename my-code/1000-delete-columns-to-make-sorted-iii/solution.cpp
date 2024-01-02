class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        int k;
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                for(k=0;k<m;k++){
                   if(strs[k][j]>strs[k][i]){
                       break;
                   }
                }
                if(k==m && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
        }

        auto maxx  = *max_element(dp.begin(),dp.end());
        return n - maxx;
    }
};
