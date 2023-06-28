class Solution {
public:
   void solve(string path,vector<string> &ans,int n,int r){

       if(n==0 && r==0){
           ans.push_back(path);
           return;
       }

       if(n>0){
       solve(path+"(",ans,n-1,r+1);
       }
       if(r>0){
            solve(path+")",ans,n,r-1);
       }

   }



    vector<string> generateParenthesis(int n) {
        string path;
        vector<string> ans;
        solve(path,ans,n,0);
        return ans;
    }
};
