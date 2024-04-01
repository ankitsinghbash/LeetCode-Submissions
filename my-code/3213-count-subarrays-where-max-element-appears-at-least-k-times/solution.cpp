class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, int k) {
        ll ans=0;
        int left=0;
        int right=0;
        int maxx_cnt=0;
        auto maxx = *max_element(nums.begin(),nums.end());
        while(right<nums.size()){
             if(nums[right]==maxx){
                maxx_cnt++;
             }

             while(maxx_cnt>=k){
                  ans+=nums.size()-right;
                  if(nums[left]==maxx){
                    maxx_cnt--;
                  }
                  left++;
             }
             right++;
        }
        return ans;
    }
};

