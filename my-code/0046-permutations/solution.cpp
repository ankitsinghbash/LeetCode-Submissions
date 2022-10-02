class Solution {
public:
    vector<vector<int>> ans;

    void helper(int i,vector<int> nums)
    {
        if(i==nums.size())
        {
            ans.push_back(nums);
            return;
        }

       for(int j=i;j<nums.size();j++)
       {
           swap(nums[i],nums[j]);   //swap every element form its position:
           helper(i+1,nums);
           //backtrack:
           swap(nums[i],nums[j]);
       }

    }

    vector<vector<int>> permute(vector<int>& nums) {
    int i=0;
    helper(i,nums);
    return ans;
    }
};
