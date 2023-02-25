class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size();++i){
            int low = lower-nums[i];
            int upp = upper-nums[i];
            ans+=upper_bound(nums.begin()+i+1,nums.end(),upp)-lower_bound(nums.begin()+i+1,nums.end(),low);
        }
        return ans;
    }
  
};
