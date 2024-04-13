class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();


        vector<vector<int>> dp(n,vector<int>(m));

        int maxx=0;
        for(int j=0;j<m;j++){
            dp[n-1][j] = matrix[n-1][j]-'0';
            if(dp[n-1][j]>maxx){
                maxx  = dp[n-1][j];
            }
        }
        for(int i=0;i<n;i++){
            dp[i][m-1] = matrix[i][m-1]-'0';
            if(dp[i][m-1]>maxx){
                maxx = dp[i][m-1];
            }
        }


        
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(matrix[i][j]=='0'){
                    dp[i][j]=0;
                }
                else if(matrix[i][j]=='1' && matrix[i+1][j]=='1' && matrix[i+1][j+1]=='1' && matrix[i][j+1]=='1'){
                    dp[i][j] = min({dp[i+1][j],dp[i+1][j+1],dp[i][j+1]})+1;
                }
                else{
                    dp[i][j] = matrix[i][j]-'0';
                }
                if(dp[i][j]>maxx){
                    maxx = dp[i][j];
                }
            }
        }
         int ans = pow(maxx,2);
         return ans;
    }
};
