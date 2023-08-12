class Solution {
public:
   
    int searchPivot(vector<int> &nums){ //search an element in the rotated array:
      int l=0;
      int h = nums.size()-1;
      int result = -1;
      while(l<h){
          while(l<h && nums[l]==nums[l+1]){
              l++;
          }
          while(l<h && nums[h]==nums[h-1]){
              h--;
          }
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

bool binarySearch(vector<int>& nums, int target, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return true;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int pivot_search = searchPivot(nums);

    if (binarySearch(nums, target, 0, pivot_search - 1)) {
        return true;
    }

    return binarySearch(nums, target, pivot_search, n - 1);
}

};
