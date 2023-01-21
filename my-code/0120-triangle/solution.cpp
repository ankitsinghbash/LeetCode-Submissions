class Solution {
public:

  
   int solve(int i,int j,vector<vector<int>> &tr,int n,vector<vector<int>> &dp){

        if(i==n-1){
            return tr[i][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }


        int vertical = tr[i][j]+solve(i+1,j,tr,n,dp);
        int diagonal = tr[i][j]+solve(i+1,j+1,tr,n,dp);

        return dp[i][j]=min(vertical,diagonal);
       
   }


    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans = solve(0,0,triangle,n,dp);
        return ans;
    }
};
