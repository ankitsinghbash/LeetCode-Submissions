class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //count sort:
        unordered_map<int,int> mp;
        for(auto &x: nums){
            mp[x]++;
        }
        int sm = *min_element(nums.begin(),nums.end());
        int lg = *max_element(nums.begin(),nums.end());


        vector<int> ans;
        for(int i=sm;i<=lg;i++){
            auto it=mp.find(i);
            if(it!=mp.end()){
                //present:
                int cnt=it->second;
                while(cnt--){
                  ans.push_back(i);
                }
            }
        }
        return ans;
    }
};
