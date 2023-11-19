class Solution {
public:
    typedef long long ll;
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long left=0;
        ll right = 0;
        long long currsum=0;
        ll maxx=0;
        while(right<nums.size()){
             currsum+=nums[right];
             ll box = (right-left+1)*nums[right];
             ll rest = box-currsum;
             if(rest>k){
                currsum-=nums[left];
                left++;
             }
             maxx = max(maxx,right-left+1);
             right++;
        }
        return maxx;
    }
};
