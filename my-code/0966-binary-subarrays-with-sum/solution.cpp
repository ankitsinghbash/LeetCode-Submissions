class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int curr_zero = 0;
        int left=0;
        int right=0;
        int ans=0;
        int curr=0;
        while(right<nums.size()){
            curr+=nums[right];
            while(left<right && (nums[left]==0 || curr>goal)){
                curr-=nums[left];
                if(nums[left]==0){
                    curr_zero++;
                }
                else{
                    curr_zero=0;
                }
                left++;
            }
            if(curr==goal){
                 ans+=curr_zero+1;
            }
            right++;
        }
        return ans;
    }
};
