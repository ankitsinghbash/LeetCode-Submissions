class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        bool flag=true;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                flag=false;
                return i;
            }
            if(target<nums[i])
            {
                return i;
            }
        }
        if(flag==true){
            return nums.size();
        }
        //if not found add to its right position and return is position:
        
        return 0;
    }
   
};
