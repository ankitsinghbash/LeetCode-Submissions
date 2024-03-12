class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            mp[ch]++;
        }
     
        string str;
        for(int i=0;i<order.size();i++){
            char ch = order[i];
            auto it = mp.find(ch);
            if(it!=mp.end()){
                int time = mp[ch];
                mp.erase(it);
                for(int j=0;j<time;j++){
                    str+=ch;
                }
            }
        }
        for(auto it = mp.begin();it!=mp.end();it++){
                int time = it->second;
                for(int j=0;j<time;j++){
                    str+=it->first;
                }
             
        }
        return str;
    }
};
