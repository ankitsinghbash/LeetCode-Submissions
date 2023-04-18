class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        int j=0;
        int n = word1.size();
        int m = word2.size();
        string ans;
        for(int k=0;k<max(n,m);k++){
            if(k<n){
                ans.push_back(word1[k]);
            }
            if(k<m){
                ans.push_back(word2[k]);
            }
        }
        return ans;
    }
};
