class Solution {
public:
   int solve(vector<int> &nums){
      int l=0;
      int h = nums.size()-1;
      int result = -1;
      while(l<h){
          int mid = l+(h-l)/2;
          if(nums[mid]>nums[h]){
              l = mid+1;
          }
          else{
              h = mid;
             result = h;
          }
      }
     return h;
   }


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
        int pivot_idx = solve(nums);

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
