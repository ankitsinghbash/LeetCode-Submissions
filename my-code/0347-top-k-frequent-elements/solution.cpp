class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> qu;   //add from high to low:
        unordered_map<int,int> mp;
        for(auto &x : nums){
            mp[x]++;
        }

        for(auto &x : mp){
            qu.push({x.second,x.first}); //because mai second ke hisaab se sort karna chayiata hu:
        }
        
        vector<int> ans;
        while(k--){
            ans.push_back(qu.top().second);
            qu.pop();
        }
        return ans;

    }
};
