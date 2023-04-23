class Solution {
public:
  const int MOD = 1000000007;
   int solve(int i,int j,string &s,int &x,vector<int> &dp){
  
     if(i==s.size()){
         return 1;
     }
      
    if(dp[i]!=-1) return dp[i];

     
  
      long long int currsum=0;
      long long int way=0;
      for(int k=i;k<j;k++){
          int ch = s[k]-'0';
          currsum = currsum*10+ch;
          if(currsum<1 || currsum>x){
              break;
          }
          way=(way+solve(k+1,j,s,x,dp))%MOD;
      }
       return dp[i] =  way;
   }
  
    // we not solve by substring because stoi() has a define range to convert string to integer:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return solve(0,n,s,k,dp);
    }
};


