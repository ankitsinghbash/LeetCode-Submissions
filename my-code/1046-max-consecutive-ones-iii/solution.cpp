class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int right=0;
        int left=0;
        int cnt=0;
        int n = nums.size();
        int maxx=0;
        while(right<n){
            if(nums[right]==0){
                cnt++;
            }

            while(left<nums.size() && cnt>k){
                if(nums[left]==0){
                    cnt--;
                }
                left++;
            }
            maxx = max(maxx,right-left+1);
            right++;
        }
        return maxx;
    }
};
