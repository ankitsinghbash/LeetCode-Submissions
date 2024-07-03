class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                int value = nums[i][j];
                 mp[value]++;
            }
        }
   
      vector<int> ans;
      for(auto it = mp.begin();it!=mp.end();it++){
          if(it->second==n){
               ans.push_back(it->first);
          }
      }
      return ans;
    }
};
