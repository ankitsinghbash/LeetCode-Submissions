class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        int i=0;
        int n = nums.size();
        while(i<n-2){
            if(nums[i]==0){
                nums[i]=1;
                nums[i+1] = 1-nums[i+1];
                nums[i+2] = 1-nums[i+2];
                ans++;
            }
            if(i==n-3){
                if(nums[i+1]==0 || nums[i+2]==0){
                    return -1;
                }
            }
            i++;
        }
        return ans;
    }
};
