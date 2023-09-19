class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x :nums)
          mp[x]++;
        
        unordered_map<int,int> :: iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            if(it->second>=2){
                return it->first;
            }
        }
        return 0;
    }
};
