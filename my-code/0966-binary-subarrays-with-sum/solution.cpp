class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int right=0;
        int left=0;
        int curr=0;
        int cnt=0;
        int prefix_zero=0;
        while(right<nums.size()){
             curr+=nums[right];
             while(left<right && (nums[left]==0 || curr>goal)){
                if(nums[left]==1){
                    prefix_zero=0;
                }
                else{
                    prefix_zero+=1;
                }
                curr-=nums[left];
                left++;
             }
             if(curr==goal){
                cnt+=1+prefix_zero;
             }
            right++;
        }
        return cnt;
    }
};
