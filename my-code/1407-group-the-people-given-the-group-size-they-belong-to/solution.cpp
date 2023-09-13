class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> lg;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<groupSizes.size();i++){
            int val = groupSizes[i];
            mp[val].push_back(i);
            auto it = mp.find(val);
            vector<int> sec = it->second;
            if(val==sec.size()){
                lg.push_back(sec);
                mp.erase(it);
            }
        }
       
        return lg;
    }
};
