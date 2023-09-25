class Solution {
public:
    char findTheDifference(string s, string t) {
        int big=0;
        int sm=0;
        for(int i=0;i<t.size();i++){
              int val = int(t[i]);
              big+=val;
        }
        for(int i=0;i<s.size();i++){
            int val = int(s[i]);
            sm+=val;
        }

        int data = big-sm;
        char ch = static_cast<char>(data);
        return data;
    }
};
