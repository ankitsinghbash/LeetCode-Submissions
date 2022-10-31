class Solution {
public:
    int search(vector<int>& nums, int target) {
        //normally search the target;
        //i use binary serach; use when element is in sorted from:
        bool flag=true;
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]==target)
           {
               flag=false;
               return i;
           }
       }
      return -1;
    }
};
