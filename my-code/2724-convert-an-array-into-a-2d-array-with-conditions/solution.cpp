class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        while(nums.size()!=0){
            vector<int> sm;
            vector<int> again;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
             again.push_back(nums[i-1]);
            }
            else if(nums[i]!=nums[i-1]){
                 sm.push_back(nums[i-1]);
            }
        }
        int n = nums.size();
        sm.push_back(nums[n-1]);
        ans.push_back(sm);
        nums.clear();
        nums = again;
        }
        return ans;
    }
};
