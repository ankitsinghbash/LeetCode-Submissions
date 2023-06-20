class Solution {
public:
    vector<int> ans;
    int removeDuplicates(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                ans.push_back(nums[i-1]);
            }
        }
        
        
        
        int n = nums.size();
        ans.push_back(nums[n-1]);
        
        int x = ans.size();
        
        for(int i=0;i<x;i++){
            nums[i] = ans[i];
        }
        
        return x;
    }
};
