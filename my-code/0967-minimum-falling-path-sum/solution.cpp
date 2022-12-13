class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
       int n=matrix.size();  //3
       int m=matrix.size();   //3
     
       vector<vector<int>> dp(n,vector<int>(m,0));
       for(int j=0;j<m;j++){
           dp[0][j]=matrix[0][j];
       }

       for(int i=1;i<n;i++){
           for(int j=0;j<m;j++){
            if(j==0){
               dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j+1]);           
              }
              else if(j==m-1){
              dp[i][j]=matrix[i][j]+min(dp[i-1][j-1],dp[i-1][j]);
              }
              else
              {
                 int val = min(dp[i-1][j-1],dp[i-1][j]);
                 int val2 = min(val,dp[i-1][j+1]);
                 dp[i][j]=val2+matrix[i][j];
              }
           }
       }
      
      int mini = INT_MAX;
      for(int j=0;j<m;j++){
          mini=min(mini,dp[n-1][j]);
      }
      return mini;

    }
};


/*
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m=A.size();
        int n=A[0].size();
        vector<vector<int>>vec(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
            vec[0][i]=A[0][i];
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                    vec[i][j]=min(vec[i-1][j],vec[i-1][j+1])+A[i][j];
                if(j>0&&j<n-1)
                    vec[i][j]=A[i][j]+min(min(vec[i-1][j-1],vec[i-1][j]),vec[i-1][j+1]);
                if(j==n-1)
                    vec[i][j]=A[i][j]+min(vec[i-1][j],vec[i-1][j-1]);
            }
        }
        int MIN=INT_MAX;
        for(int i=0;i<n;i++)
        {
            MIN=min(MIN,vec[m-1][i]);
        }
        return MIN;
    }
};



*/


/*
 int n=matrix.size();  //3
       int m=matrix.size();   //3

       vector<vector<int>> dp(n+1,vector<int>(m));
  
      for(int j=0;j<m;j++){
          dp[0][j]=0;
      }

      for(int i=1;i<n+1;i++){
          for(int j=0;j<m;j++){
              if(j==0){
               int val = min(dp[i-1][j],dp[i-1][j+1]);
               dp[i][j]=val+matrix[i-1][j];
              }
              else if(j==m-1){
                int val = min(dp[i-1][j],dp[i-1][j-1]);
                dp[i][j]=val+matrix[i-1][j];
              }
              else
              {
                 int val1 = min(dp[i-1][j-1],dp[i-1][j]);
                 int val2 = min(val1,dp[i-1][j+1]);
                 dp[i][j]=val2+matrix[i-1][j];
              }
          }
      }


*/
