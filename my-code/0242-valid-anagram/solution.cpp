class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> window_s(26,0);
        vector<int> window_t(26,0);
        for(int i=0;i<s.size();i++){
            window_s[s[i]-'a']++;
            window_t[t[i]-'a']++;
        }
        if(window_s==window_t){
            return true;
        }
        return false;
    }
};
