class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n  = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]] = i;
        }
        
        for(int i=0;i<n;i++){
            int val = target-nums[i];
            auto it = mp.find(val);
            if(it!=mp.end() && it->second!=i){
                return {i,it->second};
            }
        }
        return {};
    }
};
