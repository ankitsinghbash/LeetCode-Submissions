class Solution {
public:
int solve(string &str1,string &str2,int idx1,int idx2,vector<vector<int>> &dp){
    if(idx1==str1.size() && idx2==str2.size()) return 0;

    if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
    
    if(idx1==str1.size()){
        int rest_val=0;
        for(int alpha=idx2;alpha<str2.size();alpha++){
            rest_val+=str2[alpha]-'a'+97;
        }
        return rest_val;
    }

    if(idx2==str2.size()){
        int rest_val = 0;
        for(int alpha=idx1;alpha<str1.size();alpha++){
            rest_val+=str1[alpha]-'a'+97;
        }
        return rest_val;
    }

    int res=0;
    if(str1[idx1]==str2[idx2]){
        res+=solve(str1,str2,idx1+1,idx2+1,dp);
    }
    else{
        res+=min(str1[idx1]-'a'+97+solve(str1,str2,idx1+1,idx2,dp),str2[idx2]-'a'+97+solve(str1,str2,idx1,idx2+1,dp));
    }
    
    return dp[idx1][idx2] = res;
}



    int minimumDeleteSum(string s1, string s2) {
        int i=0;
        int j=0;
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(s1,s2,i,j,dp);
    }
};
