class Solution {
public:
    int solve(int i,int current,int target,vector<int> &nums){
          if(i>=nums.size()){
             if(current==target){
                return 1;
             }
             return 0;
          }



          int plus = solve(i+1,current+nums[i],target,nums);
          int minum = solve(i+1,current-nums[i],target,nums);




          return plus+minum;


    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,0,target,nums);
    }
};
