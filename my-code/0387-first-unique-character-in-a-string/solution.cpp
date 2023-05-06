class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        for(int i=0;i<s.size();i++){
            char ch = s.at(i);
            auto it = mp.find(ch);
            if(it->second==1){
                return i;
            }
        }
        return -1;
    }
};
