class Solution {
public:
    int solve(string word1,string word2,int idx1,int idx2,vector<vector<int>> &dp){
        if(idx1>=word1.size()){
            //get->rest to word2
            return word2.size()-idx2;
        }
        if(idx2>=word2.size()){
            return word1.size()-idx1;
        }

        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }

        if(word1[idx1]==word2[idx2]){
            return dp[idx1][idx2]=solve(word1,word2,idx1+1,idx2+1,dp);
        }

        int op1=0,op2=0,op3=0;
        op1 = solve(word1,word2,idx1+1,idx2+1,dp);
        op2 = solve(word1,word2,idx1+1,idx2,dp);
         op3 = solve(word1,word2,idx1,idx2+1,dp);
 
       return dp[idx1][idx2]=min({op1,op2,op3})+1;

    }


    int minDistance(string word1, string word2) {
        //two approach:
        vector<vector<int>> dp(501,vector<int>(501,-1));
        return solve(word1,word2,0,0,dp);
    }
};
