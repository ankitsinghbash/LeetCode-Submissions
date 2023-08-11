class Solution {
public:

    int Iscnt(int mid,vector<int> &nums){
         int i=0;
         int n = nums.size();
         int pair=0;
         while(i<n){
             if(i+1<n && nums[i+1]-nums[i]<=mid){
                 pair++;
                 i+=2;
             }
             else{
                 i++;
             }
         }
         return pair;
    }


    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int low=0;
        int result = INT_MAX;
        int high = nums[n-1]-nums[0];
        while(low<=high){
            int mid = low+(high-low)/2;
            if(Iscnt(mid,nums)>=p){
                result = mid;
                high=mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return result;


    }
};
