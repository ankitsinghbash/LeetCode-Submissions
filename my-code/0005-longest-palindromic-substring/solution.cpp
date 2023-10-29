class Solution{
public:
    int dp[1001][1001];
    bool ispalindromic(int i,int j,string &x){
        if(i>j){
            return 1;
        }
  
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
 
        if(x[i]==x[j]){
            return dp[i][j] = ispalindromic(i+1,j-1,x);
        }else{
            return dp[i][j] = 0;
        }
    }

    string longestPalindrome(string s) {
        memset(dp,-1,sizeof(dp));
        int maxx = INT_MIN;
        int start=0;
        int end = 0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++){
                if(ispalindromic(i,j,s)){
                    if(j-i+1>maxx){
                        start = i;
                        end = j;
                        maxx = j-i+1;
                    }
                }
            }
        }
        string str = s.substr(start,end-start+1);
        return str;
    }
};
