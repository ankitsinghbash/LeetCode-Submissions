class Solution {
public:

  
    int solve(string s,int idx,int n,vector<int> &dp){

      if(idx>=n){   //means when we decoded the all string because our idx getout of box also: means decoding happen:
          return 1;
      }
      
      if(dp[idx]!=-1){
          return dp[idx];
      }
      
   
      int ans=0;  //this does not means ki answer update all time as 0 no : prev ans +=new ans;
      int op1 = s[idx]-'0';
      int op2=0;
      if(idx<n-1){
          op2=op1*10+s[idx+1]-'0';
      }
      if(op1>0){
         ans+=solve(s,idx+1,n,dp);
      }
      if(op1>0 && op2>0 && op2<=26){
          ans+=solve(s,idx+2,n,dp);
      }

     return dp[idx]=ans;

    }

    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,-1);
      return   solve(s,0,n,dp);
      
    }
};
