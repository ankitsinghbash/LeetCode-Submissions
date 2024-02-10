class Solution {
public:
    int cnt=0;
    bool check(string &s){
        int low=0;
        int high = s.size()-1;
        while(low<=high){
            if(s[low]!=s[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }

    void solve(int idx,string &s){
          if(idx==s.size()) return;

          for(int i=1;i<=s.size()-idx;i++){
              string str = s.substr(idx,i);
              if(check(str)){
                  cnt++;
              }
          }

          solve(idx+1,s);
    }


    int countSubstrings(string s) {
        solve(0,s);
        return cnt;
    }
};
