class Solution {
public:
    int countKeyChanges(string s) {
        int cnt=0;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1] || s[i] == tolower(s[i-1]) || s[i]==toupper(s[i-1])){
                continue;
            }
            cnt++;
        }
        return cnt;
    }
};
