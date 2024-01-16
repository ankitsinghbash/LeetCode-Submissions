class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high = nums.size()-1;
        int result=0;
        if(target<nums[0]){
               return 0;
        }
        else if(target>nums[high]){
            return nums.size();
        }

        while(low<high){
            int mid = (low+high)/2;
            if(nums[mid]<target){
                low = mid+1;
                result = low;
            }
            else{
                high = mid;
            }
        }
        return result;
    }
};
