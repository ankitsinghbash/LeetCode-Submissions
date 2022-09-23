class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
 
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                return i;
            }
        }
        
        //means element is not found:
        int j=0;
        int counter=0;
        while(j<nums.size())
        {
            if(nums[j]<target)
            {
                counter++;
            }
            j++;
        }
        return counter;
    }
};
