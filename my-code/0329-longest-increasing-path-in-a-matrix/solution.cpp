class Solution {
public:
  
  
    int dfs(vector<vector<int>> &matrix,int i,int j,vector<vector<int>> &dp){
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
 
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
   
        int maxx=0;
        for(int k=0;k<4;k++){
  
           int x = i+dir[k].first;
           int y = j+dir[k].second;

           if(x<0 || x>=matrix.size() || y>=matrix[0].size() || y<0){
               continue;
           }
           if(matrix[x][y]<=matrix[i][j]){
               continue;
           }
             maxx=max(maxx,dfs(matrix,x,y,dp));   //also put in else condition:
        

        }
        return dp[i][j]=maxx+1;

    }
   

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int res=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                res =  max(res,dfs(matrix,i,j,dp));
            }
        }
        return res;
    }
};
