class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       vector<pair<int,int>> v;
       for(int i=0;i<nums.size();i+=2)
       {
           v.push_back(make_pair(nums[i],nums[i+1]));
       }
       int val=0;
       for(int i=0;i<v.size();i++)
       {
           val+=min(v[i].first,v[i].second);
       }
       return val;
    }
};
