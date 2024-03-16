class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0]=-1;
        int curr_sum=0;
        int maxx=0;
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i]==1?1:-1;
            if(mp.find(curr_sum)!=mp.end()){
                maxx = max(i-mp[curr_sum],maxx);
            }
            if(mp.find(curr_sum)==mp.end()){
               mp[curr_sum]=i;
            }
        }
        return maxx;
    }
};
