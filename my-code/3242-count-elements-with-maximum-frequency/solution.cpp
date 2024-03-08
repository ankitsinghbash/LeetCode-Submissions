class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int maxx=0;
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second>maxx){
                maxx=it->second;
            }
        }
        int cnt=0;
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second==maxx){
              cnt+=it->second;
            }
        }
        return cnt;
    }
};
