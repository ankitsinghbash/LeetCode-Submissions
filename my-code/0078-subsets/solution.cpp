class Solution {
public:
//imp i ko increament karne ki koi jarurat nahi beacuase recursion me khud hi hota hai:
   vector<vector<int>> ans;

   void helper(int i,vector<int> &subset,vector<int> nums)
   {
       if(nums.size()==i)
       {
           ans.push_back(subset);
           return;
       }
     
         helper(i+1,subset,nums);  //not include next:first time it got empty:
         subset.push_back(nums[i]);
         helper(i+1,subset,nums);    //include next:
         subset.pop_back();

   }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> empty;
        helper(0,empty,nums);
        return ans;
    }
};
