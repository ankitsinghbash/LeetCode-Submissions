class Solution {
public:
   bool solve(int i,int j,int k,string s1,string s2,string s3,vector<vector<int>> &dp){
      if(i==s1.size() && j==s2.size() && k==s3.size()){
           return true;
       }
    
       if(dp[i][j]!=-1){
           return dp[i][j]; 
       }

        bool left = false;
        bool right = false;
        if(i<s1.size() && s1[i]==s3[k]){
            left = solve(i+1,j,k+1,s1,s2,s3,dp);
        }

        if(j<s2.size() && s2[j]==s3[k]){
          right =  solve(i,j+1,k+1,s1,s2,s3,dp);
        }


       return dp[i][j] = left||right;

   }


    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(101,vector<int>(101,-1));
        return solve(0,0,0,s1,s2,s3,dp);
    }
};
