class Solution {
public:
    
// _________________________
// |min(2,2,3)+1        [2] | //so formuala is min({(i+1,j),(i+1,j+1),(i,j+1)})
// |                        |
// | [2]                [3] |
// |________________________|


    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxx=0;
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=0;i<n;i++){
            dp[i][m-1]=matrix[i][m-1]-'0';
            maxx = max(maxx,dp[i][m-1]);
        }
        for(int j=0;j<m;j++){
            dp[n-1][j] = matrix[n-1][j]-'0';
            maxx = max(maxx,dp[n-1][j]);
        }
        
        for(int j=m-2;j>=0;j--){
            for(int i=n-2;i>=0;i--){
                if(matrix[i][j]=='0'){
                    dp[i][j]=0;
                }
                else if(matrix[i+1][j+1]=='0' || matrix[i+1][j]=='0' || matrix[i][j+1]=='0'){
                    dp[i][j]=matrix[i][j]-'0';
                }
                else{
                    dp[i][j] = min({dp[i+1][j+1],dp[i+1][j],dp[i][j+1]})+1;
                }
                maxx = max(maxx,dp[i][j]);
            }
        } 
        
         return pow(maxx,2);
    }
};


