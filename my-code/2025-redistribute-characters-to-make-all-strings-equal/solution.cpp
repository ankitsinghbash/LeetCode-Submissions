class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> mp;
        for(int i=0;i<words.size();i++){
            for(char ch : words[i]){
                mp[ch]++;
            }
        }
        
        int n = words.size();
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second%n!=0){
                return false;
            }
        }
        return true;
    }
};
