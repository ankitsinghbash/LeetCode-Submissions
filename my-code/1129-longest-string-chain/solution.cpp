class Solution {
public:
   bool isValid(string &A,string &B){
    if(A.size()>=B.size()) return false;  //Not imp condition cover by:
    if(A.size()+1!=B.size()) return false;   //this line:

    int i=0;
    int j=0;
    while(j<B.size() && i<A.size()){
        if(A.at(i)==B.at(j)){
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    
    while(j<B.size()){   //pcxbc && pcxbcf taken and try Run:
       j++;
    }

    if(i==A.size() && j==B.size()){
        return true;
    }
    return false;
   }


    

   int solve(int prev,int idx,vector<string> &words,vector<vector<int>> &dp){
      if(idx>words.size()) return 0;

      if(dp[idx][prev]!=-1) return dp[idx][prev];

      int pick = 0;
      int notpick = 0;
      notpick = solve(prev,idx+1,words,dp);
      if(prev==0 || isValid(words[prev-1],words[idx-1])){
          pick =  1+solve(idx,idx+1,words,dp);
      }
     return dp[idx][prev] =  max(pick,notpick);
   }
 
   static bool cmp(string a,string b){
       return b.size()>a.size();
   }


    int longestStrChain(vector<string>& words) {
        vector<vector<int>> dp(words.size()+1,vector<int>(words.size()+1,-1));
        sort(words.begin(),words.end(),cmp); //sorting becuase we required first size smaller then next in isValid function:
        return solve(0,1,words,dp);
    }
};
