class Solution {
public:
    int binary_search(vector<int> &nums,int data){
          int low=0;
          int high=nums.size()-1;
          int result = -1;
          while(low<=high){
              int mid = low+(high-low)/2;
              if(nums[mid]==data){
                  result = mid;
                  return result;
              }
              else if(nums[mid]<data){
                    low = mid+1;
              }
              else{
                    high = mid-1;
              }
          }
          return result;

    }

    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxx = -1;
        for(int i=0;i<nums.size();i++){
              int value = nums[i];
              if(binary_search(nums,-value)!=-1){
                   maxx = max(maxx,abs(value));
              }
        }
 


        return maxx;
    }
};
