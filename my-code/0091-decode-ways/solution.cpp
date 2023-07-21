class Solution {
public:
   int dp[101];
   int solve(int idx,string s){
    if(idx>s.size()) return 0;

    if(idx==s.size()) return 1;
 
     if(dp[idx]!=-1) return dp[idx];

     int ans =0;
     int op1 = s[idx]-'0';  //option1:
     if(op1>0 && op1<=26){
          ans+=solve(idx+1,s);
     }
     int op2;
     if(idx+1<s.size()){
      op2 = 10*op1+s[idx+1]-'0';
     }
     if(op1>0 && op2>0 && op2<=26){
         ans+=solve(idx+2,s);
     }
     return dp[idx] = ans;
   }


    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};
