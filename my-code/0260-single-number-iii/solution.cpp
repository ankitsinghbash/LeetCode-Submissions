class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second==1){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};
