class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int  minSum = nums[0];
        int curMax=0;
        int  curMin=0;
        int totalSum = 0;
        for(auto num : nums){
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);
            totalSum+=num;
        }
        return maxSum>0? max(maxSum, totalSum-minSum) : maxSum;

    }
};
