class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &v : nums){
            mp[v]++;
        }
       
        vector<int> ans;
        int Pair = 0 ;
        int leftvalue  = 0;

        for(auto it=mp.begin();it!=mp.end();it++){
            int rightside = it->second;
            Pair+=rightside/2;
            leftvalue+=rightside%2;
        }
        ans.push_back(Pair);
        ans.push_back(leftvalue);
        return ans;

    }
};
