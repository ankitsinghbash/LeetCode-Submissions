class Solution {
public:
   const int mod = 1e9+7;
   int solve(int i,int j,vector<vector<pair<bool,char>>> &matrix,int cnt,int n,vector<vector<vector<int>>> &dp){
           //condition of out:
            if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j].second=='X'){
               return 0;
           }

            if(cnt>n){
               return 0;
           }

            //base case:
             if(cnt==n-1){
               return 1;
             }

            if(dp[i][j][cnt]!=-1){
                return dp[i][j][cnt];
            }

            int total=0;
            //int all call:
            total = (total%mod+solve(i-2,j+1,matrix,cnt+1,n,dp)%mod)%mod;
            total = (total%mod+solve(i-1,j+2,matrix,cnt+1,n,dp)%mod)%mod;
            total =  (total%mod+solve(i+1,j+2,matrix,cnt+1,n,dp)%mod)%mod;
            total = (total%mod+solve(i+2,j+1,matrix,cnt+1,n,dp)%mod)%mod;

            total= (total%mod+solve(i+2,j-1,matrix,cnt+1,n,dp)%mod)%mod;
            total = (total%mod+solve(i+1,j-2,matrix,cnt+1,n,dp)%mod)%mod;
            total = (total%mod + solve(i-1,j-2,matrix,cnt+1,n,dp)%mod)%mod;
            total =  (total%mod+solve(i-2,j-1,matrix,cnt+1,n,dp)%mod)%mod;
            return   dp[i][j][cnt] = total%mod;
       
   }



    int knightDialer(int n) {
        vector<vector<pair<bool, char>>> matrix(4, vector<pair<bool, char>>(3, {false, 'L'}));
        matrix[3][0] = {false, 'X'};
        matrix[3][2] = {false, 'X'};
       

      
       vector<vector<vector<int>>> dp(4,vector<vector<int>>(3,vector<int>(n,-1)));
       long long int total=0;
       for(int i=0;i<matrix.size();i++){
           for(int j=0;j<matrix[i].size();j++){
                
                if(matrix[i][j].second=='L'){
                    total = (total%mod + solve(i,j,matrix,0,n,dp)%mod)%mod;
                }
           }
       }
       return total;

    }
};
