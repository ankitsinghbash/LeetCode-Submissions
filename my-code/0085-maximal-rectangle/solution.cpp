class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size()));
       // dp.clear();// --> as mat karo error ayage -> only when we copy our data to new_matrix:
        int maxarea=0;
        for(int i=0;i<matrix.size();i++){
          for(int j=0;j<matrix[0].size();j++){
            if (i == 0){
              if(matrix[i][j]=='0'){
                dp[i][j]=0;
              }
              else{
                dp[i][j]=1;
              }
            }
            else{
               if(matrix[i][j]=='0'){
                 dp[i][j]=0;
               }
               else{
                 dp[i][j]=dp[i-1][j]+1;
               }
            }
            int min = dp[i][j];
            for (int k = j; k >= 0; k--){
               if (min == 0) break;    
               if (dp[i][k] < min) min = dp[i][k];  //i->mean same line me:    //maximum area in histogram me small update kar ke range(idx) se multiple karte hai:-> 2,5   so for 5 -> left me 2 aya ho ki small hai so left me 2 ko pick karo or uska area find karo 2*index val:
               maxarea = max(maxarea, min * (j - k + 1));
             }
          }
        }

        for(int i=0;i<dp.size();i++){
          for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
          }
          cout<<endl;
        }
        return maxarea;

    }

  
};
