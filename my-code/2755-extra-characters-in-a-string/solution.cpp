class Solution {
public:
  int dp[51];
  int solve(int idx,string s,unordered_set<string> &st){
     if(idx>=s.size()){
         return 0;
     }

     if(dp[idx]!=-1){
         return dp[idx];
     }

     int mini = s.size(); //maximum happen n:
     string str = "";
     
     for(int i=idx;i<s.size();i++){
         str+=s[i];
         int currlen=0;
         if(st.find(str)==st.end()){
             currlen = str.size();
         }

         int newlen = solve(i+1,s,st);
         int total = currlen+newlen;
         mini= min(mini,total);
     }


   return dp[idx] =  mini;
  }




    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp,-1,sizeof(dp));
        unordered_set<string> st;
        for(string ch : dictionary){
            st.insert(ch);
        }
        return solve(0,s,st);
    }
};
