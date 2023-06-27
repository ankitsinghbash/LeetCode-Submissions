class Solution {
public:
    vector<vector<string>> store;
    bool ispalindromic(int start,int last,string &s){
      while(start<=last){
          if(s[start]!=s[last]){
              return false;
          }
          start++;
          last--;
      }
      return true;
    }


    void solve(string s,int idx,vector<string> &path){
     if(idx==s.size()){
         store.push_back(path);
         return;
     }

      for(int i=idx;i<s.size();i++){
          if(ispalindromic(idx,i,s)){
             string str = s.substr(idx,i-idx+1);
             path.push_back(str);
             solve(s,i+1,path);
             path.pop_back();
          }
      }
    }


    vector<vector<string>> partition(string s) {
        vector<string> path;
        solve(s,0,path);
        return store;
    }
};
