class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int pos_idx=0;
        int neg_idx=1;
        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            if(val>=0){
                ans[pos_idx] = val;
                pos_idx=pos_idx+2;
            }
            else{
                ans[neg_idx] = val;
                neg_idx = neg_idx+2;
            }
        }
        return ans;
    }
};
