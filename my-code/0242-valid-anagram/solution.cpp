class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_vec(26);
        for(char ch : s){
            s_vec[ch-'a']++;
        }
        vector<int> t_vec(26);
        for(char ch : t){
            t_vec[ch-'a']++;
        }
        return s_vec==t_vec;
    }
};
