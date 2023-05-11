class Solution {
public:
   int dp[1001][1001];
   int solve(int idx,int currheight,int currwidth,vector<vector<int>> &books,int shelWidth){


       if(idx>=books.size()) return currheight;
   
       if(dp[idx][currwidth]!=-1){
           return dp[idx][currwidth];
       }

       int pick = INT_MAX;
       int notpick = INT_MAX;
       if(currwidth+books[idx][0]<=shelWidth){  //lie on same level:
           pick = solve(idx+1,max(currheight,books[idx][1]),currwidth+books[idx][0],books,shelWidth);
       }
       notpick = currheight + solve(idx+1,books[idx][1],books[idx][0],books,shelWidth);  //lie on new level:
  
       return  dp[idx][currwidth] = min(pick,notpick);

   }


    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,books,shelfWidth);
    }
};
