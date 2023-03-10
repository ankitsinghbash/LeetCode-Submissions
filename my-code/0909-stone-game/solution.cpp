class Solution {
public:
  
   int solve(int a,int b,vector<int> &piles,vector<vector<int>> &dp){
       if(a==b) return piles[a];   
 
       if(dp[a][b]!=-1){
           return dp[a][b];
       }
  
       int first = piles[a]+solve(a+1,b,piles,dp);
       int last = piles[b]+solve(a,b-1,piles,dp);
       return dp[a][b]=max(first,last);  //because both play optimally:
   }
 
 
    bool stoneGame(vector<int>& piles) {

        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int myscore = solve(0,n-1,piles,dp);
        int total = 0;
        for(int i=0;i<piles.size();i++){
            total+=piles[i];
        }
        int opp_score = total-myscore;
        if(myscore>opp_score) return true;
        else return false;
    }
};
