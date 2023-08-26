class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<int> dp(n,1);
        sort(pairs.begin(),pairs.end());
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                int curr = pairs[i][0];
                int prev = pairs[j][1];
                if(curr>prev){
                    dp[i] = max(dp[j]+1,dp[i]);
                }
            }
        }

        int maxx = INT_MIN;
        for(int i=0;i<n;i++){
             maxx = max(maxx,dp[i]);
        }
        return maxx;
       
    }
};
