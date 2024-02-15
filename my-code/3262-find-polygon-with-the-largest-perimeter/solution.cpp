
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long curr=0;
        long long maxx = -1;
        int i=0;
        int n = nums.size();
        while(i<=n-3){
             curr+=nums[i];
             if(curr+nums[i+1]>nums[i+2]){
                 long long val = curr + nums[i+1] + nums[i+2];
                 if(val>=maxx){
                     maxx = val;
                 }
             }
            i++;
        }
        return maxx;
    }
};
