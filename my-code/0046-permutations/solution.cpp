class Solution {
public:
    vector<vector<int>> ans;
    void solve(int idx,int n,vector<int> nums){

     if(idx==n){
         ans.push_back(nums);
         return;
     }
      
      for(int i=idx;i<n;i++){
          swap(nums[i],nums[idx]);
          solve(idx+1,n,nums);
      }
    }




    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        solve(0,n,nums);
        return ans;
    }
};
