class Solution {
public:
   //Now find the last index of positive value;_minimum:
     int solve(vector<int> &nums){
         int low=0;;
         int high=nums.size()-1;
         while(low<=high){
             int mid = low+(high-low)/2;
             if(nums[mid]>0){
                 high=mid-1;
             }
             else{
                 low=mid+1;
             }
         }
         return low;
     }

     //maximum idx of negative:
     int solve1(vector<int> &nums){
           int low=0;
           int high=nums.size()-1;
           while(low<=high){
               int mid = low+(high-low)/2;
               if(nums[mid]<0){
                   low=mid+1;
               }
               else{
                   high = mid-1;
               }
           }
           return high;

     }
       

    int maximumCount(vector<int>& nums) {
        int total= nums.size();
        //first index of positive;
        int positive_start= solve(nums);
        int positive = total-positive_start;
       
        //last index of negative
        int negative_idx = solve1(nums);
        return max(positive,negative_idx+1);
    }
};
