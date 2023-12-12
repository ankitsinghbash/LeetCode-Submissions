class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size()-1;
        int z = nums.size()-2;
        int x = nums[n]-1;
        int y = nums[z]-1;
        return x*y;
    }
};
