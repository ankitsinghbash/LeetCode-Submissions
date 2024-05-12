class Solution {
public:    
    int minFallingPathSum(vector<vector<int>>& grid) {
        //method1:recursion:

        //method2:tablution:

       
         
         int n = grid.size();
         vector<vector<int>> dp(n,vector<int>(n));
         for(int j=0;j<n;j++){
             dp[0][j] = grid[0][j];
         }

         for(int i=1;i<n;i++){    //current one Level:
            for(int j=0;j<n;j++){
                //logic part:
                int curr = INT_MAX;
                for(int k=0;k<n;k++){   //above col for  i: 1 level less then current one:
                      if(j!=k){
                           curr = min(curr,grid[i][j]+dp[i-1][k]);
                      }
                }
                dp[i][j] = curr;
   
            }
         }


         int mini=INT_MAX;
         for(int j=0;j<n;j++){
             int value = dp[n-1][j];
             mini = min(mini,value);
         }

         return mini;


    }
};
