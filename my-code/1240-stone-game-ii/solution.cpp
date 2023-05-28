class Solution {
public:
   int solve(int i,int player1,int M,vector<int> &piles,vector<vector<vector<int>>> &dp){ //player1 indicate alice:
         if(i>=piles.size()) return 0;

         if(dp[player1][i][M]!=-1){
             return dp[player1][i][M];
         }

         int result = (player1==1) ? INT_MIN : INT_MAX;

         int total = 0;
         for(int j=0;j<2*M;j++){
              
             if(i+j<piles.size()){ 
             total+=piles[i+j];
             }

             if(player1==1){
                 //alice:
                 result = max(result,total+solve(i+j+1,0,max(M,j+1),piles,dp)); //add total for alice only:
             }
             else{
                 result = min(result,solve(i+j+1,1,max(M,j+1),piles,dp));
             }
         }
        return dp[player1][i][M] =  result;


   }



    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return solve(0,1,1,piles,dp); 
    }
};
