class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
       //Find the actual lcs string:
       int n = text1.size();
       int m = text2.size();

    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
      dp[i][0]=0;
    }
    for(int j=0;j<m+1;j++){
      dp[0][j]=0;
    }
    for(int i=1;i<n+1;i++){
      for(int j=1;j<m+1;j++){
        if(text1[i-1]==text2[j-1]){
          dp[i][j]=1+dp[i-1][j-1];
        }
        else{
          dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
      }
    }
   
    
    int i=n;
    int j=m;
    string ans="";
    while(i>0 && j>0){
      if(text1[i-1]==text2[j-1]){
        ans+=text1[i-1];
        i--;
        j--;
      }
      else{
         if(dp[i-1][j]>dp[i][j-1]){
           i--;
         }
         else{
           j--;
         }
      }
    }
    reverse(ans.begin(),ans.end());
    
     //string ans me my LCS is presen:
     //Now IF the question is ask for mini length of the shortest common supersequence then --> (n+m)-lcs.size();
     i=0;
     j=0;
     cout<<ans<<endl;
     string str="";
     for(auto ch : ans){
         while(text1[i]!=ch){
             str+=text1[i];
             i++;
         }
         while(text2[j]!=ch){
             str+=text2[j];
             j++;
         }
         str+=ch;
         i++;
         j++;
     }

     return str+text1.substr(i)+text2.substr(j);

    }
};
