class Solution {
public:
    vector<vector<string>> store;
    bool ispalindromic(string str){
        int i=0;
        int j=str.size()-1;
        while(i<=j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int idx,string s,vector<string> ans){
      
             if(idx==s.size()){
                store.push_back(ans);
                return;
             }
          


          for(int i=idx;i<s.size();i++){
              string str = s.substr(idx,i-idx+1);
              //if this is palindromic string:
              if(ispalindromic(str)==true){
                   ans.push_back(str);
                   solve(i+1,s,ans);
                   ans.pop_back();
              }
          }



    }
    vector<vector<string>> partition(string s) {
        vector<string> ans;
         solve(0,s,ans);
         return store;
    }
};
