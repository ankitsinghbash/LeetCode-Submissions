class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int j=nums.size()-1;
        int last;
        while(k--){
            last = nums[j];
            j--;
        }  
        return last;
    }
};
