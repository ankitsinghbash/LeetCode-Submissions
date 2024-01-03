class Solution {
public:
    int minFlips(string target) {
        int n = target.size();
        vector<int> dp(n);
        dp[0] = (target[0]=='0')?0:1;
        for(int i=1;i<n;i++){
              if(target[i]==target[i-1]){
                  dp[i] = dp[i-1];
              }
              else{
                  dp[i]=dp[i-1]+1;
              }
        }
        return dp[n-1];
    }
};
