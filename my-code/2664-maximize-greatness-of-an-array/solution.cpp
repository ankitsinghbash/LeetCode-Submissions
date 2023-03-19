class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
      int ans=0;
      sort(nums.begin(),nums.end());
      int i=0,j=0;
      while(j<nums.size()){
          if(nums[j]>nums[i]){
              i++;
              ans++;
          }
          j++;
      }
     return ans;
    }
};
