class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
      sort(strs.begin(),strs.end());
          string ans="";
        int n=strs.size();
        for(int i=0;i<strs[0].size();i++){
            if(strs[0][i]!=strs[n-1][i]) return ans;
            else ans+=strs[0][i];
        }
        return ans;
}
};
