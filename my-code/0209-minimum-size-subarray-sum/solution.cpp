class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int curr=0;
        int right=0;
        int left=0;
        int mini = INT_MAX;
        while(right<nums.size()){
            curr+=nums[right];
            while(left<nums.size() && curr>=target){
                int len = right-left+1;
                mini = min(mini,len);
                curr-= nums[left];
                left++;
            }
            right++;
        }
        return mini==INT_MAX ? 0 : mini;
    }
};
