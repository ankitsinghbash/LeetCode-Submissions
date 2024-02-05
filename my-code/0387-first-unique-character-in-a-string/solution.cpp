class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int ans=-1;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(mp[ch]==1){
                ans = i;
                break;
            }
        }
        return ans;
    }

};
