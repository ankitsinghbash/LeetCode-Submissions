class Solution {
public:
    
    vector<vector<int>> ans;
    void helper(int i,vector<int> &nums)
    {
        if(i==nums.size())
        {
            ans.push_back(nums);
        }

        unordered_set<int> st;  //use for remove duplicaty or see the same question of gfg use direct set so we set different value:
        for(int j=i;j<nums.size();j++)
        {
            if(st.find(nums[j])!=st.end())
            {
               //value in set; so continue;
               continue;
            }
            else
            {
                //value is not in set: so put it:
                st.insert(nums[j]);
            }
            swap(nums[i],nums[j]);
            helper(i+1,nums);
            swap(nums[i],nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {    
       int i=0;
       helper(i,nums);
       return ans;
    }
};
