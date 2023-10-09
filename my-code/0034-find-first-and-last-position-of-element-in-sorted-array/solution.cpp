class Solution {
public:
    void solveleft(vector<int> &nums,vector<int> &result,int target){
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                result[0]=mid;
                high = mid-1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }


   void solveright(vector<int> &nums,vector<int> &result,int target){
       int low=0;
       int high = nums.size()-1;
       while(low<=high){
           int mid = low+(high-low)/2;
           if(nums[mid]==target){
               result[1]=mid;
               low = mid+1;
           }
           else if(nums[mid]<target){
               low=mid+1;
           }
           else{
               high = mid-1;
           }
       }
   }



    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        solveleft(nums,result,target);
        solveright(nums,result,target);
        return result;
    }
};
