class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=1;i<nums.size();i++){
              if(nums[i]==nums[i-1]){
                  nums[i]=nums[i]+1;
                  cnt++;
              }
              else if(nums[i]<nums[i-1]){
                 cnt+=abs(nums[i]-nums[i-1])+1;
                 nums[i] = nums[i-1]+1;
                 
              }
        }
        return cnt;
    }
};


//[0,2,3,2,2]
