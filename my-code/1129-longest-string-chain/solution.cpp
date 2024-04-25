class Solution {
public:
    bool isvalid(string &A,string &B){
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

   
    int solve(int prev,int curr,vector<string> &words,vector<vector<int>> &dp){
         if(curr==words.size()){
            return 0;
         }


         if(dp[prev+1][curr]!=-1) return dp[prev+1][curr];

         
         int taken=0;
         int nottaken=0;
         nottaken = solve(prev,curr+1,words,dp);
         if(prev == -1 || isvalid(words[prev],words[curr])==true){
            taken = 1+solve(curr,curr+1,words,dp);
         }
         return dp[prev+1][curr] = max(taken,nottaken);

    }
  static bool cmp(string a,string b){
       return b.size()>a.size();
   }

    int longestStrChain(vector<string>& words) {
        vector<vector<int>> dp(words.size()+1,vector<int>(words.size()+1,-1));
        sort(words.begin(),words.end(),cmp);
        return solve(-1,0,words,dp);
    }
};
