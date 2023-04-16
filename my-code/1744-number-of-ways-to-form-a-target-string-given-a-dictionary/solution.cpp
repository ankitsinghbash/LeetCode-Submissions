class Solution {
public:
   int dp[1001][1001];
   const int MOD = 1e9+7;
   int solve(int i,int j,vector<string> &words,string &target,vector<vector<long long>> &store){

     if(i>=target.size()) return 1; //mean's ek string to mil gyi:

     if(j>=words[0].size()) return 0;
 
      if(dp[i][j]!=-1) return dp[i][j];

      //nottaken;
      int nottaken = solve(i,j+1,words,target,store)%MOD;
      int taken = ((store[target[i]-'a'][j])*solve(i+1,j+1,words,target,store))%MOD;  //taken means my char target[i] ke equal hua hai then increment i also:
       
       return dp[i][j]=(nottaken+taken)%MOD;
   }



    int numWays(vector<string>& words, string target){
        int k = words[0].size();
        vector<vector<long long>> store(26,vector<long long>(k));
        for(int j=0;j<k;j++){
            for(auto &word : words){
                char ch = word[j];
                store[ch-'a'][j]++;
            }
        }
   
        memset(dp,-1,sizeof(dp));
        return solve(0,0,words,target,store);   //i for taget and j for words:
    }
};
