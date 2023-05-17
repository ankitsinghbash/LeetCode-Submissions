class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
   
        unordered_map<int,int> :: iterator it;
        for(int i=0;i<nums.size();i++){
            int rest = target-nums[i];
            auto it = mp.find(rest);
            if(it!=mp.end() && it->second!=i){
                return {i,it->second};
            }
        }
        return {};

    }
};
