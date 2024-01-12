class Solution {
public:
    // pivot is always first value after condition:
    int binary_search(int l,int h,vector<int> &nums,int target){

        while(l<=h){
            int mid = l+(h-l)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(nums[mid]<target){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return -1;
   }

    int search(vector<int>& nums, int target) {
        int low=0;
        int high = nums.size()-1;
        int result = 0;
        while(low<high){
            int mid = low+(high-low)/2;
            if(nums[mid]<=nums[high]){
                high = mid;
            }
            else{

                low = mid+1;
                result = low;
            }
        }
        int pivot_idx = result;
          int idx = binary_search(0,pivot_idx-1,nums,target);
        if(idx!=-1){
            return idx;
        }

        int idx2 = binary_search(pivot_idx,nums.size()-1,nums,target);
        if(idx2!=-1){
            return idx2;
        }
        return -1;
    }
};
