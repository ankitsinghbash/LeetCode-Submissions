class Solution {
public:
    int bs(vector<int> &nums,int target){
        int low=0;
        int high = nums.size()-1;
        int result = -1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
               result = mid;
                if(nums[mid]<target){
                low=mid+1;
               }
               else{
                high = mid-1;
                }
           
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return result;
    }

    int search(vector<int>& nums, int target) {
        return bs(nums,target);
    }
};
