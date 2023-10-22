class Solution {
public:
    int minimumSum(vector<int>& nums) {
         int result = INT_MAX;
        bool flag=true;
        int n = nums.size();
         for(int i=0;i<n;i++){
             for(int j=i+1;j<n;j++){
                 for(int k=j+1;k<n;k++){
                     if(nums[i]<nums[j] && nums[k]<nums[j]){
                         int sum = nums[i]+nums[j]+nums[k];
                         flag=false;
                         result = min(result,sum);
                     }
                 }
             }
         }
        if(flag==true){
            return -1;
        }
        return result;
        
    }
};
