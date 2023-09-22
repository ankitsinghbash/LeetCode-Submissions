class Solution {
public:
   bool solve(int i,int j,string s,string t,int n,int m){
        if(i>=n){
            return true;
        }
       
        if(j>=m){
            return false;
        }

        bool first=false;
        bool second = false;
        if(s[i]==t[j]){
            first = solve(i+1,j+1,s,t,n,m);
        }
        else{
            second = solve(i,j+1,s,t,n,m);
        }
        return first || second;
   }
    


    bool isSubsequence(string s, string t) {
        //recursive code:
        if(s.size()==0){
            return true;
        }
        if(s.size()>t.size()) return false;

        int n = s.size();
        int m = t.size();
        return solve(0,0,s,t,n,m);
    }
};


// class Solution {
// public:
//     //dp approach bottom: tabulation:
//     bool isSubsequence(string s, string t) {
//          vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
//          for(int i=0;i<s.size()+1;i++){
//              dp[i][0]=false;
//          }
//          for(int j=0;j<t.size()+1;j++){
//              dp[0][j]=true;
//          }

//          for(int i=1;i<s.size()+1;i++){
//              for(int j=1;j<t.size()+1;j++){
//                  if(s[i-1]==t[j-1]){
//                      dp[i][j]=dp[i-1][j-1];
//                  }
//                  else{
//                      dp[i][j]=dp[i][j-1];
//                  }
//              }
//          }
//          return dp[s.size()][t.size()];
//     }
// };

//Two pointer approach:
// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         int s_size = s.size();
//         int t_size = t.size();
//         if(s_size>t_size){
//             return false;
//         }
     
//         int cnt=0;
//         int i=0;
//         int j=0;
//         while(i<s_size && j<t_size){
//             if(s[i]==t[j]){
//                 cnt++;
//                 i++;
//             }
//             j++;
//         }
//         if(cnt==s_size){
//             return true;
//         }
//         return false;

//     }
// };
