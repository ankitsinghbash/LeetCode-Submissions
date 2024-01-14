class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int maxx=0;
        for(auto it = mp.begin();it!=mp.end();it++){
            maxx = max(maxx,it->second);
        }
        int ans=0;
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second==maxx){
                ans+=it->second;
            }
        }
        return ans;
    }
};
